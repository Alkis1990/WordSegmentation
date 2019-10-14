/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionInv;
    QAction *actionLine_Split;
    QAction *actionWord_Split;
    QAction *actionHorizontal_Rlsa;
    QAction *actionBatch_Process;
    QAction *actionFuzzy_Runlength;
    QAction *actionHorizontal_Rlsa_words;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QSpinBox *spinBox_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QSpinBox *spinBox_6;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QFrame *line_4;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QFrame *line;
    QFrame *line_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_8;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *spinBox_7;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QFrame *line_7;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuProc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(694, 504);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionInv = new QAction(MainWindow);
        actionInv->setObjectName(QStringLiteral("actionInv"));
        actionLine_Split = new QAction(MainWindow);
        actionLine_Split->setObjectName(QStringLiteral("actionLine_Split"));
        actionWord_Split = new QAction(MainWindow);
        actionWord_Split->setObjectName(QStringLiteral("actionWord_Split"));
        actionHorizontal_Rlsa = new QAction(MainWindow);
        actionHorizontal_Rlsa->setObjectName(QStringLiteral("actionHorizontal_Rlsa"));
        actionBatch_Process = new QAction(MainWindow);
        actionBatch_Process->setObjectName(QStringLiteral("actionBatch_Process"));
        actionFuzzy_Runlength = new QAction(MainWindow);
        actionFuzzy_Runlength->setObjectName(QStringLiteral("actionFuzzy_Runlength"));
        actionHorizontal_Rlsa_words = new QAction(MainWindow);
        actionHorizontal_Rlsa_words->setObjectName(QStringLiteral("actionHorizontal_Rlsa_words"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        spinBox_4 = new QSpinBox(centralWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMaximum(100000);
        spinBox_4->setSingleStep(500);
        spinBox_4->setValue(5000);

        horizontalLayout_4->addWidget(spinBox_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        spinBox_6 = new QSpinBox(centralWidget);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMaximum(200);
        spinBox_6->setValue(55);

        horizontalLayout_7->addWidget(spinBox_6);


        verticalLayout_3->addLayout(horizontalLayout_7);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout_3->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout_3->addWidget(pushButton_12);


        gridLayout->addLayout(verticalLayout_3, 5, 2, 1, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 4, 2, 1, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 3, 1, 1, 1);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 5, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(200);
        spinBox_2->setValue(30);

        horizontalLayout->addWidget(spinBox_2);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);


        gridLayout->addLayout(verticalLayout, 2, 2, 1, 1);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 7, 0, 1, 7);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_2->addWidget(pushButton_9, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMaximum(200);
        spinBox->setValue(70);

        horizontalLayout_2->addWidget(spinBox);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(0, 0));
        pushButton_5->setMaximumSize(QSize(16777215, 16777215));
        pushButton_5->setBaseSize(QSize(0, 0));

        horizontalLayout_2->addWidget(pushButton_5);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 3);

        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));

        gridLayout->addWidget(graphicsView_2, 0, 4, 1, 3);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 6, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 4, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 1);

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 2, 3, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(100000);
        spinBox_3->setSingleStep(500);
        spinBox_3->setValue(5000);

        horizontalLayout_3->addWidget(spinBox_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBox_5 = new QSpinBox(centralWidget);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMaximum(200);
        spinBox_5->setValue(43);

        horizontalLayout_6->addWidget(spinBox_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_2->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout_2->addWidget(pushButton_8);


        gridLayout->addLayout(verticalLayout_2, 5, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_4->addWidget(label_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.15);
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.05);
        doubleSpinBox->setValue(0.25);

        horizontalLayout_8->addWidget(doubleSpinBox);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        horizontalLayout_8->addWidget(pushButton_13);


        verticalLayout_4->addLayout(horizontalLayout_8);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        verticalLayout_4->addWidget(pushButton_14);


        gridLayout->addLayout(verticalLayout_4, 2, 4, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_5->addWidget(label_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        spinBox_7 = new QSpinBox(centralWidget);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMaximum(150);
        spinBox_7->setValue(18);

        horizontalLayout_9->addWidget(spinBox_7);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        horizontalLayout_9->addWidget(pushButton_16);


        verticalLayout_5->addLayout(horizontalLayout_9);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        verticalLayout_5->addWidget(pushButton_15);


        gridLayout->addLayout(verticalLayout_5, 2, 6, 1, 1);

        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 2, 5, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 694, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuProc = new QMenu(menuBar);
        menuProc->setObjectName(QStringLiteral("menuProc"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProc->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuProc->addAction(actionInv);
        menuProc->addAction(actionLine_Split);
        menuProc->addAction(actionWord_Split);
        menuProc->addAction(actionHorizontal_Rlsa);
        menuProc->addAction(actionHorizontal_Rlsa_words);
        menuProc->addAction(actionBatch_Process);
        menuProc->addAction(actionFuzzy_Runlength);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionInv->setText(QApplication::translate("MainWindow", "Inv", Q_NULLPTR));
        actionLine_Split->setText(QApplication::translate("MainWindow", "Line Split", Q_NULLPTR));
        actionWord_Split->setText(QApplication::translate("MainWindow", "Word Split", Q_NULLPTR));
        actionHorizontal_Rlsa->setText(QApplication::translate("MainWindow", "Horizontal Rlsa - lines", Q_NULLPTR));
        actionBatch_Process->setText(QApplication::translate("MainWindow", "Batch Process", Q_NULLPTR));
        actionFuzzy_Runlength->setText(QApplication::translate("MainWindow", "Fuzzy Runlength", Q_NULLPTR));
        actionHorizontal_Rlsa_words->setText(QApplication::translate("MainWindow", "Horizontal Rlsa - words", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Fuzzy runlength (words)", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "RL image threshold", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "FuzzyRL Max Block cnt", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "Fuzzy runlength WORDS batch", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "RLSA threshold (words)", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "RLSA WORDS batch", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "RLSA threshold (lines)", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "RLSA LINES batch", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "FitToPage", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "1:1", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Fuzzy RL (lines)", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "RL image threshold", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "FuzzyRL Max Block cnt", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Fuzzy runlength LINES batch", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Lines Detection", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "Lines Detection batch", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Words Detection", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "Words Detection batch", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuProc->setTitle(QApplication::translate("MainWindow", "Proc", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
