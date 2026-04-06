/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *wholething;
    QWidget *sidebar;
    QVBoxLayout *sidebarr;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QFrame *Header;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *btnLogTime;
    QTextBrowser *notificationsBrowser;
    QWidget *widget;
    QLabel *pieLabel;
    QTextEdit *textEdit_6;
    QLineEdit *searchLineEdit;
    QListWidget *listWidget;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1089, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1081, 531));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wholething = new QWidget(horizontalLayoutWidget);
        wholething->setObjectName("wholething");
        sidebar = new QWidget(wholething);
        sidebar->setObjectName("sidebar");
        sidebar->setGeometry(QRect(0, 0, 241, 531));
        sidebar->setStyleSheet(QString::fromUtf8("background-color: #AC9362;"));
        sidebarr = new QVBoxLayout(sidebar);
        sidebarr->setObjectName("sidebarr");
        button1 = new QPushButton(sidebar);
        button1->setObjectName("button1");
        button1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        sidebarr->addWidget(button1);

        button2 = new QPushButton(sidebar);
        button2->setObjectName("button2");
        button2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        sidebarr->addWidget(button2);

        button3 = new QPushButton(sidebar);
        button3->setObjectName("button3");
        button3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        sidebarr->addWidget(button3);

        button4 = new QPushButton(sidebar);
        button4->setObjectName("button4");
        button4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        sidebarr->addWidget(button4);

        Header = new QFrame(wholething);
        Header->setObjectName("Header");
        Header->setGeometry(QRect(240, 0, 841, 531));
        Header->setStyleSheet(QString::fromUtf8("background-color: #F5F5F5;\n"
"border-bottom: 450px solid #DDD;"));
        Header->setFrameShape(QFrame::Shape::StyledPanel);
        Header->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(Header);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 200, 378, 300));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit_3 = new QTextEdit(verticalLayoutWidget);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-weight: bold;\n"
"color: #444;"));

        verticalLayout->addWidget(textEdit_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_4);

        btnLogTime = new QPushButton(verticalLayoutWidget);
        btnLogTime->setObjectName("btnLogTime");
        btnLogTime->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}"));

        horizontalLayout_3->addWidget(btnLogTime);


        verticalLayout->addLayout(horizontalLayout_3);

        notificationsBrowser = new QTextBrowser(verticalLayoutWidget);
        notificationsBrowser->setObjectName("notificationsBrowser");
        notificationsBrowser->setStyleSheet(QString::fromUtf8("background-color: #FFF3E0;\n"
"border: 1px solid #FF9800;\n"
"border-radius: 4px;\n"
"color: #333;\n"
"font-size: 14px;\n"
"padding: 5px;"));

        verticalLayout->addWidget(notificationsBrowser);

        widget = new QWidget(Header);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(460, 200, 291, 241));
        widget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #DDD;\n"
"border-radius: 8px;"));
        pieLabel = new QLabel(widget);
        pieLabel->setObjectName("pieLabel");
        pieLabel->setGeometry(QRect(30, 10, 231, 221));
        pieLabel->setScaledContents(true);
        pieLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        textEdit_6 = new QTextEdit(Header);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(90, 0, 651, 71));
        searchLineEdit = new QLineEdit(Header);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(480, 470, 256, 41));
        searchLineEdit->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"padding: 5px;\n"
"background-color: white;\n"
"border: 1px solid #AC9362;\n"
"border-radius: 4px;\n"
"color: #333;"));
        listWidget = new QListWidget(Header);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 90, 256, 101));
        pushButton_5 = new QPushButton(Header);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(750, 470, 71, 511));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #786E45;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #473920;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}\n"
""));

        horizontalLayout->addWidget(wholething);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1089, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "USER", nullptr));
        button2->setText(QCoreApplication::translate("MainWindow", "RESOURCES", nullptr));
        button3->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        button4->setText(QCoreApplication::translate("MainWindow", "TASK MANAGER", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        btnLogTime->setText(QCoreApplication::translate("MainWindow", "Log Time", nullptr));
        pieLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        textEdit_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; color:#625838;\">Smart Carpentry Workshop Management</span></p></body></html>", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search tasks...", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", " PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
