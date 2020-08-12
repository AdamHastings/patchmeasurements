/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
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
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>


QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *start_page;
    QLabel *intro;
    QPushButton *consent_btn;
    QLabel *outline;
    QLabel *consent;
    QPushButton *not_consent_btn;
    QWidget *consent_page;
    QLabel *label_2;
    QWidget *goodbye_page;
    QWidget *task1_page;
    QWidget *patch_page;
    QWidget *task2_page;
    QWidget *q1_page;
    QWidget *q2_page;
    QWidget *q3_page;
    QWidget *q4_page;
    QWidget *wta_page;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        
        // H = MainWindow->
        // QRect rec = QApplication::desktop()->screenGeometry();
        //QRect rec = QScreen::geometry();
        QRect rec = QApplication::desktop()->screenGeometry();
        const int H = rec.height()/3;
        const int W = rec.width()/3;

        const int MARGIN = H/10;
        const int M = MARGIN;
        const int LINEWIDTH = W - (2*MARGIN);

        const int BUTTON_WIDTH = W/4;
        const int BUTTON_HEIGHT = H/16;


        /// Main setup ////////////////////////////////////////////////////////
        
        MainWindow->setMinimumSize(QSize(W, H));
        MainWindow->setMaximumSize(QSize(W, H));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(W, H));
        centralwidget->setMaximumSize(QSize(W, H));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, W, H));
        stackedWidget->setMinimumSize(QSize(W, H));
        stackedWidget->setMaximumSize(QSize(W, H));
        
        // start page /////////////////////////////////////////////////////////
        
        start_page = new QWidget();
        start_page->setObjectName(QStringLiteral("start_page"));
        
        intro = new QLabel(start_page);
        intro->setObjectName(QStringLiteral("intro"));
        intro->setGeometry(QRect(MARGIN, MARGIN, LINEWIDTH, MARGIN*3));
        intro->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        intro->setWordWrap(true);
        
        outline = new QLabel(start_page);
        outline->setObjectName(QStringLiteral("outline"));
        outline->setGeometry(QRect(MARGIN, MARGIN*4, LINEWIDTH, MARGIN*3));
        outline->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        outline->setWordWrap(true);
        
        consent = new QLabel(start_page);
        consent->setObjectName(QStringLiteral("consent"));
        consent->setGeometry(QRect(MARGIN, MARGIN*7, LINEWIDTH, MARGIN));
        consent->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        consent->setWordWrap(true);

        not_consent_btn = new QPushButton(start_page);
        not_consent_btn->setObjectName(QStringLiteral("not_consent_btn"));
        not_consent_btn->setGeometry(QRect(W/2 + MARGIN, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        
        consent_btn = new QPushButton(start_page);
        consent_btn->setObjectName(QStringLiteral("consent_btn"));
        consent_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH - MARGIN, MARGIN*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        stackedWidget->addWidget(start_page);
       
       // goodbye page ////////////////////////////////////////////////////////
       
        consent_page = new QWidget();
        consent_page->setObjectName(QStringLiteral("consent_page"));
        consent_page->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(consent_page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 81, 67, 17));
        stackedWidget->addWidget(consent_page);
        goodbye_page = new QWidget();
        goodbye_page->setObjectName(QStringLiteral("goodbye_page"));
        stackedWidget->addWidget(goodbye_page);
        task1_page = new QWidget();
        task1_page->setObjectName(QStringLiteral("task1_page"));
        task1_page->setStyleSheet(QStringLiteral("background-color:blue"));
        stackedWidget->addWidget(task1_page);
        patch_page = new QWidget();
        patch_page->setObjectName(QStringLiteral("patch_page"));
        patch_page->setStyleSheet(QStringLiteral("background-color:red"));
        stackedWidget->addWidget(patch_page);
        task2_page = new QWidget();
        task2_page->setObjectName(QStringLiteral("task2_page"));
        stackedWidget->addWidget(task2_page);
        q1_page = new QWidget();
        q1_page->setObjectName(QStringLiteral("q1_page"));
        stackedWidget->addWidget(q1_page);
        q2_page = new QWidget();
        q2_page->setObjectName(QStringLiteral("q2_page"));
        stackedWidget->addWidget(q2_page);
        q3_page = new QWidget();
        q3_page->setObjectName(QStringLiteral("q3_page"));
        stackedWidget->addWidget(q3_page);
        q4_page = new QWidget();
        q4_page->setObjectName(QStringLiteral("q4_page"));
        stackedWidget->addWidget(q4_page);
        wta_page = new QWidget();
        wta_page->setObjectName(QStringLiteral("wta_page"));
        stackedWidget->addWidget(wta_page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 22));
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
        intro->setText(QApplication::translate("MainWindow", "Thank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 20 minutes to complete.", Q_NULLPTR));
        consent_btn->setText(QApplication::translate("MainWindow", "I consent", Q_NULLPTR));
        outline->setText(QApplication::translate("MainWindow", "This experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will first have you complete some simple tasks with these modifications turned off. Later, we will turn on these modifications and ask you to complete the same set of tasks.", Q_NULLPTR));
        consent->setText(QApplication::translate("MainWindow", "Do you consent to participate in this study? You may exit the experiment at any point.", Q_NULLPTR));
        not_consent_btn->setText(QApplication::translate("MainWindow", "I do not consent", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
