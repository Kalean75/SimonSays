/********************************************************************************
** Form generated from reading UI file 'SimonUi.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMONUI_H
#define UI_SIMONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *RedButton;
    QPushButton *BlueButton;
    QLabel *LivesLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *MessageLabel;
    QProgressBar *progressBar;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *StartButton;
    QPushButton *EasyMode;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(400, 399);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 112, 112);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        RedButton = new QPushButton(centralWidget);
        RedButton->setObjectName(QString::fromUtf8("RedButton"));
        RedButton->setGeometry(QRect(10, 70, 181, 191));
        RedButton->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"selection-background-color: rgb(255, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        BlueButton = new QPushButton(centralWidget);
        BlueButton->setObjectName(QString::fromUtf8("BlueButton"));
        BlueButton->setEnabled(true);
        BlueButton->setGeometry(QRect(210, 70, 181, 191));
        BlueButton->setAutoFillBackground(false);
        BlueButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(0, 85, 255);\n"
"border-color: rgb(0, 0, 0);"));
        BlueButton->setAutoDefault(false);
        LivesLabel = new QLabel(centralWidget);
        LivesLabel->setObjectName(QString::fromUtf8("LivesLabel"));
        LivesLabel->setGeometry(QRect(250, 280, 131, 41));
        QFont font;
        font.setPointSize(15);
        LivesLabel->setFont(font);
        LivesLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 10, 241, 48));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MessageLabel = new QLabel(widget);
        MessageLabel->setObjectName(QString::fromUtf8("MessageLabel"));
        MessageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(MessageLabel);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(160, 270, 82, 56));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        StartButton = new QPushButton(widget1);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setEnabled(true);
        StartButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(StartButton);

        EasyMode = new QPushButton(widget1);
        EasyMode->setObjectName(QString::fromUtf8("EasyMode"));
        EasyMode->setEnabled(true);
        EasyMode->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(EasyMode);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        RedButton->setText(QString());
        BlueButton->setText(QString());
        LivesLabel->setText(QString());
        MessageLabel->setText(QString());
        StartButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        EasyMode->setText(QCoreApplication::translate("MainWindow", "EasyMode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMONUI_H
