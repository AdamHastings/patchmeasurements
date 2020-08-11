/********************************************************************************
** Form generated from reading UI file 'color-switch-tutorial.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QLabel *label;
    QWidget *Yellow_page;
    QWidget *Blue_page;
    QWidget *Red_page;
    QPushButton *blu_btn;
    QPushButton *red_btn;
    QPushButton *ylw_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 30, 711, 441));
        Home = new QWidget();
        Home->setObjectName(QStringLiteral("Home"));
        label = new QLabel(Home);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 170, 191, 121));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        stackedWidget->addWidget(Home);
        Yellow_page = new QWidget();
        Yellow_page->setObjectName(QStringLiteral("Yellow_page"));
        Yellow_page->setStyleSheet(QStringLiteral("background-color:yellow"));
        stackedWidget->addWidget(Yellow_page);
        Blue_page = new QWidget();
        Blue_page->setObjectName(QStringLiteral("Blue_page"));
        Blue_page->setStyleSheet(QStringLiteral("background-color:blue"));
        stackedWidget->addWidget(Blue_page);
        Red_page = new QWidget();
        Red_page->setObjectName(QStringLiteral("Red_page"));
        Red_page->setStyleSheet(QStringLiteral("background-color:red"));
        stackedWidget->addWidget(Red_page);
        blu_btn = new QPushButton(centralwidget);
        blu_btn->setObjectName(QStringLiteral("blu_btn"));
        blu_btn->setGeometry(QRect(120, 510, 89, 25));
        red_btn = new QPushButton(centralwidget);
        red_btn->setObjectName(QStringLiteral("red_btn"));
        red_btn->setGeometry(QRect(360, 500, 89, 25));
        ylw_btn = new QPushButton(centralwidget);
        ylw_btn->setObjectName(QStringLiteral("ylw_btn"));
        ylw_btn->setGeometry(QRect(600, 500, 89, 25));
        ylw_btn->setStyleSheet(QStringLiteral("background"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Please click the desired button below to get the color you want", Q_NULLPTR));
        blu_btn->setText(QApplication::translate("MainWindow", "Blue", Q_NULLPTR));
        red_btn->setText(QApplication::translate("MainWindow", "Red", Q_NULLPTR));
        ylw_btn->setText(QApplication::translate("MainWindow", "Yellow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
