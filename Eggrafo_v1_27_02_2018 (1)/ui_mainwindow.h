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
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_6;
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
        MainWindow->resize(694, 414);
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 3, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 4);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 2);

        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));

        gridLayout->addWidget(graphicsView_2, 0, 2, 1, 2);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

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


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

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
        pushButton->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "FitToPage", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "1:1", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Horizontal RLSA threshold (lines)", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Horizontal RLSA threshold (words)", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
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
