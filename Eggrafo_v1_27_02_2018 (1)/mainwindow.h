#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileInfo>
#include <QSpinBox>
#include <QMessageBox>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();

private:
    enum eView
    {
        first,
        second
    };

    Ui::MainWindow *ui;

    void openFile();
    void openFileHelper(QString const &filePath);
    void Exit();

    uint Iy;
    uint Ix;
    int bpp;

    QImage *Image1;
    QImage *Image2;
    QGraphicsScene *scene1;
    QGraphicsScene *scene2;

    QSpinBox spinBox;
    QSpinBox spinBox_2;
    QSpinBox spinBox_3;
    QSpinBox spinBox_4;
    QSpinBox spinBox_5;
    QSpinBox spinBox_6;
    QSpinBox spinBox_7;
    QDoubleSpinBox doubleSpinBox;

    string datFilename;
    QFileInfo openedFileInfo;
    bool bBatchActive;

    void Inv();
    void LineSplit();
    void WordSplit();
    void HorizontalRlsa();
    void HorizontalRlsaWords();
    void BatchProcess();
    void BatchProcessHelper(bool bLines, bool bwords, bool bRlsaLines, bool bRlsaWords, bool bFuzzyLines, bool bFuzzyWords);
    void FuzzyRlsa();
    void FuzzyRlsaWords();


    void SetImageToView(QImage *pImg, eView view);
    bool CheckImageIsLoaded();
    void ConvertQImageToRGB888();
};

#endif // MAINWINDOW_H
