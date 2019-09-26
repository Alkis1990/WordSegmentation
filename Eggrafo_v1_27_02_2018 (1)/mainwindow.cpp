#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDebug>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

#include "Util.h"



using namespace cv;
using namespace std;

/// Global variables

/** General variables */
Mat src, edges;
Mat src_gray;

cv::Vec3b red(255,0,0);
cv::Vec3b green(0,255,0);
cv::Vec3b blue(0,0,255);
cv::Vec3b brown(255, 255, 0);
cv::Vec3b greenblue(0, 255, 255);
cv::Vec3b purple(255, 0, 255);

cv::Vec3b colours[] = {red, blue, green, brown, greenblue, purple};

cv::Vec3b black(0, 0, 0);

/////////////////////////////////////////////
//helper functions

void findPeaks(vector<float> x0, vector<int>& peakInds);
void horRlsa(const Mat &imgIn, Mat &imgOut, int rlsaThres);
void convertQImageToMat(QImage *qImg, Mat &matImg);
void convertMatToQimage(Mat &matImg, QImage *qImg);
std::vector<int> linesPosition(Mat &img, Mat &bitmapOfTag, std::vector<int> &histogram);
void fuzzyRlsa(const Mat &imgIn, Mat &imgOut);
void blobDetectionLines(Mat &imgGray, Mat &mask, int minWidth, int minHeight);
/////////////////////////////////////////////


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Image1 = NULL;
    Image2 = NULL;
    Iy=0;
    Ix=0;
    bpp=0;
    bBatchActive = false;

    scene1 = new QGraphicsScene;
    ui->graphicsView->setScene(scene1);
    scene2 = new QGraphicsScene;
    ui->graphicsView_2->setScene(scene2);

    // sender, signal, receiver, slot
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::Exit);
    connect(ui->actionInv, &QAction::triggered, this, &MainWindow::Inv);
    connect(ui->actionLine_Split, &QAction::triggered, this, &MainWindow::LineSplit);
    connect(ui->actionWord_Split, &QAction::triggered, this, &MainWindow::WordSplit);
    connect(ui->actionHorizontal_Rlsa, &QAction::triggered, this, &MainWindow::HorizontalRlsa);
    connect(ui->actionHorizontal_Rlsa_words, &QAction::triggered, this, &MainWindow::HorizontalRlsaWords);
    connect(ui->actionBatch_Process, &QAction::triggered, this, &MainWindow::BatchProcess);
    connect(ui->actionFuzzy_Runlength, &QAction::triggered, this, &MainWindow::FuzzyRlsa);
}

void clearImage(QImage *img)
{
    if(img!=NULL)
    {
        delete img;
        img = NULL;
    }
}

MainWindow::~MainWindow()
{
    clearImage(Image1);
    clearImage(Image2);
    delete scene1;
    delete scene2;
    delete ui;
}

void MainWindow::BatchProcess()
{
    //select directory to process contents
    QDir directory = QFileDialog::getExistingDirectory(this, tr("select directory"));
    QStringList imageList = directory.entryList(QStringList() << "*.tif" << "*.TIF" << "*.jpg" << "*.JPG" ,QDir::Files);
    bBatchActive = true;
    QString information = "Batch Prossess active for Directory: " + directory.absolutePath();
    ui->label->setText(information);
    foreach(QString imageFile, imageList) {
        //open file
        openFileHelper(directory.absoluteFilePath(imageFile));
        //find lines
        LineSplit();
        //find words
        WordSplit();
        //rlsa lines
        HorizontalRlsa();
        //rlsa words
        HorizontalRlsaWords();
    }
    bBatchActive = false;
    information = "Batch Prossess for Directory: " + directory.absolutePath() + " is Finished";
    ui->label->setText(information);
}


void MainWindow::SetImageToView(QImage *pImg, eView view)
{
    if(pImg==NULL) return;
    if(view == eView::first)
    {
        scene1->clear();
        scene1->addPixmap(QPixmap::fromImage(*pImg));
    }
    else
    {
        scene2->clear();
        scene2->addPixmap(QPixmap::fromImage(*pImg));
    }
}

void MainWindow::openFileHelper(QString const &filePath)
{
    QFile *f;
    f = new (std::nothrow) QFile(filePath);

    if(f->exists())
    {
        clearImage(Image1);
        Image1 =  new (std::nothrow) QImage(f->fileName());
        openedFileInfo = QFileInfo(*f);
        datFilename = openedFileInfo.fileName().toStdString() + ".dat";

        Ix = Image1->width();
        Iy = Image1->height();
        bpp = Image1->depth();

        if (!bBatchActive) //when batch process we do not need to visualize images, information or results
        {
            SetImageToView(Image1, eView::first);

            QString information = "BPP: "+QString::number(bpp)+"\nWidth: "+QString::number(Ix)+"\nHeight: "+QString::number(Iy);
            ui->label->setText(information);
        }
    }
}

void MainWindow::openFile()
{
    bBatchActive = false;
    QString flPath = QFileDialog::getOpenFileName(this, tr("Open File"),QCoreApplication::applicationDirPath(),tr("Images (*.png *.tif *.jpg *.bmp)"));
    openFileHelper(flPath);
}


void MainWindow::Inv()
{
    clearImage(Image2);
    Image2 = new (std::nothrow) QImage(Ix,Iy,QImage::Format_RGB32);

    for(uint y=0;y<Iy;y++)
    {
        for(uint x=0;x<Ix;x++)
        {            
            unsigned char u = (unsigned char) qGray(Image1->pixel(x,y));
            Image2->setPixel(x, y, qRgb(255-u,255-u,255-u));
        }
    }

    SetImageToView(Image2, eView::second);
}


void MainWindow::LineSplit() {

    if(!CheckImageIsLoaded()) { return; }

    ConvertQImageToRGB888();

    Mat image1, tagImage;

    convertQImageToMat(Image2, image1);

    std::vector<int> linesHist;
    std::vector<int> linesIndex = linesPosition(image1,tagImage,linesHist);

    if(!bBatchActive) //show output if Batch is inactive
    {
        //normalize histogram and add it into final image
        auto result = std::minmax_element (linesHist.begin(), linesHist.end());
        int max = *result.second;
        int min = *result.first;

        for (uint i = 0; i < linesHist.size(); ++i)
        {
          linesHist[i] = (linesHist[i] - min) * 60 / (max - min);
          for (uint c=0; c < linesHist[i]; ++c)
          {
            image1.at<Vec3b>(Point(c,i)) = black;
          }
        }

        //color image1 using tagImage to show lines
        for(int r=0; r<tagImage.rows; ++r){
            for(int c=0; c<tagImage.cols; ++c){
                uchar tagValue = tagImage.at<uchar>(r,c);
                if (tagValue == 0) {continue;}

                image1.at<Vec3b>(Point(c,r)) = colours[tagValue % 6];
            }
        }

        convertMatToQimage(image1, Image2);
        SetImageToView(Image2, eView::second);
    }

    //store file
    string fpath(openedFileInfo.absolutePath().toStdString() +"/dat_lines/");
    QDir dir(QString(fpath.c_str()));
    if(!dir.exists())
    {
        openedFileInfo.absoluteDir().mkdir("dat_lines");
    }
    fpath += datFilename;
    FILE *fp = fopen(fpath.c_str(),"wb+");  //Copying the Image to filename.dat file
    uchar ch[4];
    memset(ch,0,4);
    for(int r=0; r<tagImage.rows; ++r)
        for(int c=0; c<tagImage.cols; ++c){
            ch[0] = tagImage.at<uchar>(r,c);
            fwrite(&ch, sizeof(int), 1, fp);
        }

    fclose(fp);

}

void detectWords(Mat &imgIn, Mat &bitmapOfTag)
{
    Mat imgGray;
    cvtColor(imgIn, imgGray, CV_BGR2GRAY);
    // morphological gradient
    Mat grad;
    Mat morphKernel = getStructuringElement(MORPH_ELLIPSE, Size(6, 6));
    morphologyEx(imgGray, grad, MORPH_GRADIENT, morphKernel);
    // binarize
    Mat bw;
    threshold(grad, bw, 0.0, 255.0, THRESH_BINARY | THRESH_OTSU);
    // connect horizontally oriented regions
    Mat connected;
    morphKernel = getStructuringElement(MORPH_RECT, Size(18, 1));
    morphologyEx(bw, connected, MORPH_CLOSE, morphKernel);

    //store tags of words in image
    bitmapOfTag = Mat::zeros(imgGray.size(), CV_8UC1);
    uchar tag=1;
    // find contours
    Mat mask = Mat::zeros(bw.size(), CV_8UC1);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    hierarchy.size();
    findContours(connected, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    // filter contours
    for (int idx=contours.size()-1; idx>=0; idx--)
    {
        Rect rect = boundingRect(contours[idx]);
        Mat maskROI(mask, rect);
        maskROI = Scalar(0, 0, 0);
        // fill the contour
        drawContours(mask, contours, idx, Scalar(255, 255, 255), CV_FILLED);
        // ratio of non-zero pixels in the filled region
        double r = (double)countNonZero(maskROI)/(rect.width*rect.height);

        if (r > .1 /* assume at least 10% of the area is filled if it contains text */
            && (rect.height > 14 && rect.width > 24)) /* constraints on region size */
        {

            cv::Mat TagRoi = bitmapOfTag(rect);
            cv::Mat TagGray = imgGray(rect);
            cv::Mat TagConnected = connected(rect);
            vector<int> wordHist(TagGray.cols, 0);;
            for (int i=0;i<TagRoi.cols;i++)
            {
              int blacks=0;
              for(int j=0;j<TagRoi.rows;j++)
              {
                  if(TagGray.at<uchar>(j,i) < 100)
                  {
                     TagRoi.at<uchar>(j,i) = tag;

                  }
                  if (TagConnected.at<uchar>(j,i) < 100)
                  {
                     blacks++;
                  }
              }
              wordHist[i]=blacks;
            }
            tag++;

            //print wordhist above word's rectangle
            //normalize histogram and add it into final image
            auto result = std::minmax_element (wordHist.begin(), wordHist.end());
            int max = *result.second;
            int min = *result.first;

            uint col = rect.x;
            for (uint i = 0; i < wordHist.size(); ++i)
            {
              wordHist[i] = (wordHist[i] - min) * 20 / (max - min);
              uint row = rect.y;
              for (uint r=0; r < wordHist[i]; ++r)
              {
                imgIn.at<Vec3b>(Point(col,row)) = black;
                row--;
              }
              col++;
            }

            //rectangle(imgOut, rect, Scalar(0, 255, 0), 2);
        }
    }
    //imshow("tagssss",bitmapOfTag);

}

void MainWindow::WordSplit()
{
    if(!CheckImageIsLoaded()) { return; }

    ConvertQImageToRGB888();
    Mat image1;
    convertQImageToMat(Image2, image1);
    Mat tagImage;

    detectWords(image1, tagImage);

    if(!bBatchActive) //show output if Batch is inactive
    {
        //color image1 using tagImage to show lines
        for(int r=0; r<tagImage.rows; ++r){
            for(int c=0; c<tagImage.cols; ++c){
                uchar tagValue = tagImage.at<uchar>(r,c);
                if (tagValue == 0) {continue;}

                image1.at<Vec3b>(Point(c,r)) = colours[tagValue % 6];
            }
        }

        convertMatToQimage(image1, Image2);
        SetImageToView(Image2, eView::second);
    }

    string fpath(openedFileInfo.absolutePath().toStdString() +"/dat_words/");
    QDir dir(QString(fpath.c_str()));
    if(!dir.exists())
    {
        openedFileInfo.absoluteDir().mkdir("dat_words");
    }
    fpath += datFilename;
    FILE *fp = fopen(fpath.c_str(),"wb+");  //Copying the Image to filename.dat file
    uchar ch[4];
    memset(ch,0,4);
    for(int r=0; r<tagImage.rows; ++r)
        for(int c=0; c<tagImage.cols; ++c){
            ch[0] = tagImage.at<uchar>(r,c);
            fwrite(&ch, sizeof(int), 1, fp);
        }
    fclose(fp);

}

void MainWindow::Exit()
{
    QCoreApplication::exit(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->scale(0.9,0.9);
    ui->graphicsView_2->scale(0.9,0.9);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scale(1.1,1.1);
    ui->graphicsView_2->scale(1.1,1.1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsView->resetMatrix();
    ui->graphicsView_2->resetMatrix();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->graphicsView->fitInView(scene1->sceneRect(),Qt::KeepAspectRatio);
    ui->graphicsView_2->fitInView(scene2->sceneRect(),Qt::KeepAspectRatio);
}

void MainWindow::on_pushButton_5_clicked(){  //OK: for Binary Threshold

        //int result = QMessageBox::question(this, "Binarization", buffer, QMessageBox::Ok | QMessageBox::Cancel);
        HorizontalRlsa();
}

void MainWindow::on_pushButton_6_clicked()
{
        HorizontalRlsaWords();
}

//expects grayscale image as input parameter
std::vector<int> linesPosition(Mat &img, Mat &bitmapOfTag, std::vector<int> &histogram)
{
    Mat imageRLSA;
    int rlsaThres = 70;
    horRlsa(img, imageRLSA, rlsaThres);

    Mat &gray = imageRLSA;
    uchar threshhold = 127;

    //create horizontal hist
    std::vector<int> blacksVec(gray.rows, 0);
    std::vector<int> blacksRowVec(gray.rows, 0);
    for (int x = 0; x<gray.rows; x++) {
       int blacks = 0;
       int blacksRow = 0;
       for (int y = 0; y<gray.cols/4; y++) {
           // count black pixels per line
           if (gray.at<uchar>(x, y) < threshhold) {
               if(y<gray.cols/4)
               {
                   blacks++; //quarter of row
               }
               blacksRow++;
           }
       }
       blacksVec[x]=blacks;
       blacksRowVec[x]=blacksRow;
    }
    histogram = blacksRowVec;

    //Find peaks in histogram
    vector<float> blacksVecFloat(blacksVec.size());
    for(uint i=0; i< blacksVecFloat.size(); i++)
    {
        blacksVecFloat[i] = (float)blacksVec[i];
    }
    vector<int> peaks;
    findPeaks(blacksVecFloat,peaks);

    //clen up peaks that are too close (double counted lines)
    //find median of space between neighbouring peaks
    vector<int> spaces(peaks.size()-1);
    for(uint i=0; i< peaks.size()-1; i++)
    {
       spaces[i] = peaks[i+1] - peaks[i];
    }
    sort(spaces.begin(),spaces.end());
    int median = spaces[spaces.size()/2];

    std::vector<int>::iterator iter = peaks.begin();
    iter++; //measure space between current and previous peaks so move to second one.
    while (iter != peaks.end())
    {
        if(*iter - *std::prev(iter)< (median - (median/3)))
        {   //if distance is smaller than median minus a third of median erase peak.
            iter = peaks.erase(iter); // erase returns the next pos
        }
        else
        {
            ++iter;
        }
    }
    Mat imgInGray;
    cvtColor(img, imgInGray, CV_BGR2GRAY);
    bitmapOfTag = Mat::zeros(gray.size(), CV_8UC1);
    uint tag = 1;
    int bottomOfLine = 0;
    int topOfLine;

    for (uint i = 0; i < peaks.size(); ++i)
    {
        if (i == peaks.size() - 1) //last row top
        {
            topOfLine = gray.rows-1;
        }
        else
        {
            topOfLine = (peaks[i] + peaks[i+1])/2;
        }

        for(int r = bottomOfLine; r < topOfLine; r++ )
        {
            for (int c=0; c<bitmapOfTag.cols; c++)
            {
                if(imgInGray.at<uchar>(r,c) < 100)
                {
                   bitmapOfTag.at<uchar>(r,c) = tag;
                }
            }
        }

        bottomOfLine = topOfLine; //for next iteration, previous line top + 1;
        tag++;
    }

    return peaks;
}

void lineSplit(const string &imgFilepath)
{
    Mat image = imread(imgFilepath);
    Mat tagImage;
    //std::vector<int> linesIndex = linesPosition(image,tagImage);

    //show out put
    //storebat
}

void horRlsa(const Mat &imgIn, Mat &imgOut, int rlsaThres)
{
    cvtColor(imgIn, imgOut, CV_BGR2GRAY);

    int thres = 100; //binarization threshold

    for(int x=0;x<imgIn.rows;x++)
    {
        int last_black_pos=-1;  //last black pixel position
        for(int y=0;y<imgIn.cols;y++)
        {
            if((int)imgOut.at<uchar>(x,y) > thres) // white pixel
                continue;

            if(last_black_pos==-1) //init last black pixel position for every line
            {
                last_black_pos = y;
            }

            int apostash = y-last_black_pos;
            if(apostash>1)
            {
                int sum_white = apostash - 1;
                if(sum_white<=rlsaThres) //paint it black!
                {
                    for(int c=(last_black_pos+1); c<=(y-1);c++)
                    {
                       imgOut.at<uchar>(x,c) = (uchar)0;
                    }
                }
            }

            last_black_pos = y;
        }
    }
}

//image is grayscale and has already blobs to detect
void blobDetectionLines(Mat &imgGray, Mat &mask, int minWidth, int minHeight)
{
    uchar tag=1;
    // find contours
    mask = Mat::zeros(imgGray.size(), CV_8UC1);
    Mat bw;
    threshold(imgGray, bw, 0.0, 255.0, THRESH_BINARY | THRESH_OTSU);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    hierarchy.size();
    findContours(bw, contours, hierarchy, RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    // filter contours
    for (int idx = contours.size()-1; idx>=1; idx--)
    {
        Rect rect = boundingRect(contours[idx]);

        if (rect.height > minHeight && rect.width > minWidth) /* constraints on region size */
        {
              // fill the contour
              drawContours(mask, contours, idx, Scalar(tag), CV_FILLED);
              tag++;
        }
    }
//    imshow("img Rows detected",mask);
}

void MainWindow::FuzzyRlsa()
{
    if(!CheckImageIsLoaded()) { return; }

    ConvertQImageToRGB888();

    Mat image1;
    convertQImageToMat(Image2, image1);
    Mat imageRLSA;
    fuzzyRlsa(image1, imageRLSA);

    if(!bBatchActive) //show output if Batch is inactive
    {
        //color image1 using tagImage to show lines
//        for(int r=0; r<tagImage.rows; ++r){
//            for(int c=0; c<tagImage.cols; ++c){
//                uchar tagValue = tagImage.at<uchar>(r,c);
//                if (tagValue == 0) {continue;}

//                image1.at<Vec3b>(Point(c,r)) = colours[tagValue % 6];
//            }
//        }

        convertMatToQimage(imageRLSA, Image2);
        SetImageToView(Image2, eView::second);
    }

}

void fuzzyRlsa(const Mat &imgIn, Mat &imgOut)
{
    Mat imgGray;
    cvtColor(imgIn, imgGray, CV_BGR2GRAY);
    Mat imgTmp(imgGray.rows,imgGray.cols,CV_32SC1);
    //imgOut = Mat(imgGray.rows,imgGray.cols,CV_8UC1,Scalar::all(0));
    int thres = 100; //binarization threshold
    uint maxBlockCnt = 43;

    //left to right
    for(int x=0;x<imgIn.rows;x++)
    {
        std::queue<int> BlkQ;
        for(int y=0;y<imgIn.cols;y++)
        {
            if((int)imgGray.at<uchar>(x,y) < thres) // black pixel
                BlkQ.push(y);

            if(BlkQ.size() > maxBlockCnt)
            {
                imgTmp.at<int>(x,y) = y - BlkQ.front();
                BlkQ.pop();
            }
            else
            {
                if(y != 0)
                    imgTmp.at<int>(x,y) = imgTmp.at<int>(x,y-1)+1;
                else
                    imgTmp.at<int>(x,y) = imgTmp.at<int>(x,0)+1;
            }
        }
    }
    //right to left
    for(int x=imgIn.rows-1;x>=0;x--)
    {
        std::queue<int> BlkQ;
        for(int y=imgIn.cols-1;y>=0;y--)
        {
            if((int)imgGray.at<uchar>(x,y) < thres) // black pixel
                BlkQ.push(imgIn.cols-1-y);

            if(BlkQ.size() > maxBlockCnt)
            {
                imgTmp.at<int>(x,y) = (imgIn.cols-1 - y) - BlkQ.front();
                BlkQ.pop();
            }
            else
            {
                if(y != imgIn.cols-1)
                    imgTmp.at<int>(x,y) += imgTmp.at<int>(x,y+1)+1;
                else
                    imgTmp.at<int>(x,y) += imgTmp.at<int>(x,imgIn.cols-1)+1;
            }
        }
    }

    double min, max;
    cv::minMaxLoc(imgTmp, &min, &max);
    qDebug(string("min:" + to_string(min) + " max:" + to_string(max)).c_str());
    //Mat normalizedImg(imgGray.rows,imgGray.cols,CV_8UC1);
    //cv::normalize(imgTmp,  normalizedImg, 0, 255, cv::NORM_MINMAX);

    imshow("Fuzzy runlength",imgTmp);
    Mat dest;
    //threshold output image by saving result to imgOut.
    int thres1 = 5000;
    //imgTmp.setTo(0,imgTmp<=thres1);
    //imgTmp.setTo(2248257,imgTmp>thres1);
    imgOut = Mat::zeros(imgGray.size(), CV_8UC1);
    imgOut.setTo(255,imgTmp>thres1);
}


void convertQImageToMat(QImage *qImg, Mat &matImg)
{
     matImg=cv::Mat( qImg->height(), qImg->width(), CV_8UC3,
                   const_cast<uchar*>(qImg->bits()),
                   static_cast<size_t>(qImg->bytesPerLine())).clone();
}

void convertMatToQimage(Mat &matImg, QImage *qImg)
{
    clearImage(qImg);
    QImage::Format format;
    switch(matImg.type())
    {
    case CV_8UC1:
        format = QImage::Format_Grayscale8;
        break;
    case CV_8UC3:
        format = QImage::Format_RGB888;
        break;
    default:
        qDebug("error on converting Mat to QImage. Non supported format");
        return;
    }

    qImg = new (std::nothrow)QImage( matImg.data,
                matImg.cols, matImg.rows,
                static_cast<int>(matImg.step),
                format);
}

void MainWindow::ConvertQImageToRGB888()
{
    clearImage(Image2);
    Image2 = new QImage(Ix,Iy,QImage::Format_RGB888);
    for (uint y = 0; y < Iy; y++)
    {
        for (uint x = 0; x < Ix; x++)
        {
            Image2->setPixelColor(x,y,Image1->pixel(x,y));
        }
    }
}

bool MainWindow::CheckImageIsLoaded()
{
    if(!Image1)
    {
        QMessageBox box;
        box.warning(this,QString("Warning!"),QString("No image is loaded! Use File -> Open, to load one"));
        return false;
    }
    return true;
}

void MainWindow::HorizontalRlsaWords()
{
    if(!CheckImageIsLoaded()) { return; }

    ConvertQImageToRGB888();

    Mat image1;
    convertQImageToMat(Image2, image1);
    Mat imageRLSA;

    QString spinB_Threshold = ui->spinBox_2->text();
    int rlsaThres = spinB_Threshold.toInt();
    if (rlsaThres < 1) { rlsaThres = 1;}
    horRlsa(image1, imageRLSA, rlsaThres);
    Mat maskImage;
    blobDetectionLines(imageRLSA, maskImage, 30, 20);
    Mat imageGray;
    cvtColor(image1, imageGray, CV_BGR2GRAY);
    if(!bBatchActive) //show output if Batch is inactive
    {
        //show rlsa image
        imshow("RLSA image - words", imageRLSA);
        //color image1 using maskImage to show lines
        for(int r=0; r<maskImage.rows; ++r){
            for(int c=0; c<maskImage.cols; ++c){
                uchar maskValue = maskImage.at<uchar>(r,c);
                if (maskValue == 0 || imageGray.at<uchar>(r,c)>120 ) {continue;}
                image1.at<Vec3b>(Point(c,r)) = colours[maskValue % 6];
            }
        }

        convertMatToQimage(image1, Image2);
        SetImageToView(Image2, eView::second);
    }

    //store file
    string fpath(openedFileInfo.absolutePath().toStdString() +"/dat_words_rlsa/");
    QDir dir(QString(fpath.c_str()));
    if(!dir.exists())
    {
        openedFileInfo.absoluteDir().mkdir("dat_words_rlsa");
    }
    fpath += datFilename;
    FILE *fp = fopen(fpath.c_str(),"wb+");  //Copying the Image to filename.dat file
    uchar ch[4];
    memset(ch,0,4);
    for(int r=0; r<maskImage.rows; ++r)
        for(int c=0; c<maskImage.cols; ++c){
            ch[0] = maskImage.at<uchar>(r,c);
            fwrite(&ch, sizeof(int), 1, fp);
        }

    fclose(fp);
}

void MainWindow::HorizontalRlsa() //lines
{    
    if(!CheckImageIsLoaded()) { return; }

    ConvertQImageToRGB888();

    Mat image1;
    convertQImageToMat(Image2, image1);
    Mat imageRLSA;

    QString spinB_Threshold = ui-> spinBox->text();
    int rlsaThres = spinB_Threshold.toInt();
    if (rlsaThres < 1) { rlsaThres = 1;}
    horRlsa(image1, imageRLSA, rlsaThres);
    Mat maskImage;
    blobDetectionLines(imageRLSA, maskImage, 150, 30);
    Mat imageGray;
    cvtColor(image1, imageGray, CV_BGR2GRAY);
    if(!bBatchActive) //show output if Batch is inactive
    {
        //show rlsa image
        imshow("RLSA image - lines", imageRLSA);
        //color image1 using maskImage to show lines
        for(int r=0; r<maskImage.rows; ++r){
            for(int c=0; c<maskImage.cols; ++c){
                uchar maskValue = maskImage.at<uchar>(r,c);
                if (maskValue == 0 || imageGray.at<uchar>(r,c)>120 ) {continue;}
                image1.at<Vec3b>(Point(c,r)) = colours[maskValue % 6];
            }
        }

        convertMatToQimage(image1, Image2);
        SetImageToView(Image2, eView::second);
    }

    //store file
    string fpath(openedFileInfo.absolutePath().toStdString() +"/dat_lines_rlsa/");
    QDir dir(QString(fpath.c_str()));
    if(!dir.exists())
    {
        openedFileInfo.absoluteDir().mkdir("dat_lines_rlsa");
    }
    fpath += datFilename;
    FILE *fp = fopen(fpath.c_str(),"wb+");  //Copying the Image to filename.dat file
    uchar ch[4];
    memset(ch,0,4);
    for(int r=0; r<maskImage.rows; ++r)
        for(int c=0; c<maskImage.cols; ++c){
            ch[0] = maskImage.at<uchar>(r,c);
            fwrite(&ch, sizeof(int), 1, fp);
        }

    fclose(fp);
}



