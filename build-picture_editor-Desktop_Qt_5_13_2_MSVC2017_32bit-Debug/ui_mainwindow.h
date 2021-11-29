/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *displayImage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *blurButton;
    QPushButton *brightButton;
    QPushButton *contrastButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *sliderLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1298, 856);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(38, 43, 61);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        displayImage = new QLabel(centralwidget);
        displayImage->setObjectName(QString::fromUtf8("displayImage"));
        displayImage->setGeometry(QRect(30, 50, 1241, 621));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 0, 481, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        loadButton = new QPushButton(horizontalLayoutWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"background-color: rgb(71, 99, 107);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout->addWidget(loadButton);

        saveButton = new QPushButton(horizontalLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout->addWidget(saveButton);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(260, 750, 811, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        blurButton = new QPushButton(horizontalLayoutWidget_2);
        blurButton->setObjectName(QString::fromUtf8("blurButton"));
        blurButton->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout_2->addWidget(blurButton);

        brightButton = new QPushButton(horizontalLayoutWidget_2);
        brightButton->setObjectName(QString::fromUtf8("brightButton"));
        brightButton->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout_2->addWidget(brightButton);

        contrastButton = new QPushButton(horizontalLayoutWidget_2);
        contrastButton->setObjectName(QString::fromUtf8("contrastButton"));
        contrastButton->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout_2->addWidget(contrastButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-color: rgb(12, 211, 204);\n"
"color: rgb(12, 211, 204);"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(340, 699, 651, 41));
        sliderLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        sliderLayout->setObjectName(QString::fromUtf8("sliderLayout"));
        sliderLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1298, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Picture editor\360\237\216\250", nullptr));
        displayImage->setText(QString());
        loadButton->setText(QCoreApplication::translate("MainWindow", "Open\360\237\223\202", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save\360\237\222\276", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        blurButton->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        brightButton->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        contrastButton->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
