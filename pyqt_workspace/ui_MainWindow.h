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

#include <QApplication>
#include <QDesktopWidget>

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

    QWidget *start_page;
    QLabel *intro_label;
    QPushButton *consent_btn;
    QLabel *outline_label;
    QLabel *consent_label;
    QPushButton *not_consent_btn;
    QWidget *consent_page;
    
    QWidget *goodbye_page;
    QLabel *goodbye_label;
    QPushButton *goodbye_btn;

    // void setBluePage(bool b) {
    //     stackedWidget->setCurrentWidget(Blue_page);
    // }

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));


        QRect rec = QApplication::desktop()->screenGeometry();
        const int H = rec.height()/2;
        const int W = rec.width()/2;

        const int MARGIN = H/10;
        const int M = MARGIN;
        const int LINEWIDTH = W - (2*MARGIN);

        const int BUTTON_WIDTH = W/4;
        const int BUTTON_HEIGHT = H/16;


        // MainWindow->setMinimumSize(QSize(800, 600));
        // MainWindow->setMaximumSize(QSize(800, 600));
        // centralwidget = new QWidget(MainWindow);
        // centralwidget->setObjectName(QStringLiteral("centralwidget"));
        // stackedWidget = new QStackedWidget(centralwidget);
        // stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        // stackedWidget->setGeometry(QRect(40, 30, 711, 441));

        MainWindow->setMinimumSize(QSize(W, H));
        MainWindow->setMaximumSize(QSize(W, H));
        QWidget* centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(W, H));
        centralwidget->setMaximumSize(QSize(W, H));
        QStackedWidget* stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, W, H));
        stackedWidget->setMinimumSize(QSize(W, H));
        stackedWidget->setMaximumSize(QSize(W, H));


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

        start_page = new QWidget();
        start_page->setObjectName(QStringLiteral("start_page"));
        
        intro_label = new QLabel(start_page);
        intro_label->setObjectName(QStringLiteral("intro_label"));
        intro_label->setGeometry(QRect(MARGIN, MARGIN, LINEWIDTH, MARGIN*3));
        intro_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        intro_label->setWordWrap(true);
              
        outline_label = new QLabel(start_page);
        outline_label->setObjectName(QStringLiteral("outline_label"));
        outline_label->setGeometry(QRect(MARGIN, MARGIN*4, LINEWIDTH, MARGIN*3));
        outline_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        outline_label->setWordWrap(true);
        
        consent_label = new QLabel(start_page);
        consent_label->setObjectName(QStringLiteral("consent_label"));
        consent_label->setGeometry(QRect(MARGIN, MARGIN*7, LINEWIDTH, MARGIN));
        consent_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        consent_label->setWordWrap(true);
        
        consent_btn = new QPushButton(start_page);
        consent_btn->setObjectName(QStringLiteral("consent_btn"));
        consent_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH - M, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        not_consent_btn = new QPushButton(start_page);
        not_consent_btn->setObjectName(QStringLiteral("not_consent_btn"));
        not_consent_btn->setGeometry(QRect(W/2 + M, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        stackedWidget->addWidget(start_page);



        goodbye_page = new QWidget();
        goodbye_page->setObjectName(QStringLiteral("goodbye_page"));

        goodbye_label = new QLabel(goodbye_page);
        goodbye_label->setObjectName(QStringLiteral("outline"));
        goodbye_label->setGeometry(QRect(M, M, LINEWIDTH, M*4));
        goodbye_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        goodbye_label->setWordWrap(true);

        goodbye_btn = new QPushButton(goodbye_page);
        goodbye_btn->setObjectName(QStringLiteral("goodbye_btn"));
        goodbye_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        stackedWidget->addWidget(goodbye_page);




        MainWindow->setCentralWidget(centralwidget);
        // menubar = new QMenuBar(MainWindow);
        // menubar->setObjectName(QStringLiteral("menubar"));
        // menubar->setGeometry(QRect(0, 0, 800, 22));
        // MainWindow->setMenuBar(menubar);
        // statusbar = new QStatusBar(MainWindow);
        // statusbar->setObjectName(QStringLiteral("statusbar"));
        // MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        // QObject::connect(blu_btn, blu_btn->clicked, stackedWidget, &Ui_MainWindow::setBluePage);

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
