/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(600, 400));
        centralwidget->setMaximumSize(QSize(600, 400));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 600, 400));
        stackedWidget->setMinimumSize(QSize(600, 400));
        stackedWidget->setMaximumSize(QSize(600, 400));
        start_page = new QWidget();
        start_page->setObjectName(QString::fromUtf8("start_page"));
        intro = new QLabel(start_page);
        intro->setObjectName(QString::fromUtf8("intro"));
        intro->setGeometry(QRect(40, 10, 511, 121));
        intro->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        intro->setWordWrap(true);
        consent_btn = new QPushButton(start_page);
        consent_btn->setObjectName(QString::fromUtf8("consent_btn"));
        consent_btn->setGeometry(QRect(120, 290, 131, 25));
        outline = new QLabel(start_page);
        outline->setObjectName(QString::fromUtf8("outline"));
        outline->setGeometry(QRect(40, 120, 511, 101));
        outline->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        outline->setWordWrap(true);
        consent = new QLabel(start_page);
        consent->setObjectName(QString::fromUtf8("consent"));
        consent->setGeometry(QRect(40, 220, 511, 41));
        consent->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        consent->setWordWrap(true);
        not_consent_btn = new QPushButton(start_page);
        not_consent_btn->setObjectName(QString::fromUtf8("not_consent_btn"));
        not_consent_btn->setGeometry(QRect(320, 290, 141, 25));
        stackedWidget->addWidget(start_page);
        consent_page = new QWidget();
        consent_page->setObjectName(QString::fromUtf8("consent_page"));
        consent_page->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(consent_page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 81, 67, 17));
        stackedWidget->addWidget(consent_page);
        goodbye_page = new QWidget();
        goodbye_page->setObjectName(QString::fromUtf8("goodbye_page"));
        stackedWidget->addWidget(goodbye_page);
        task1_page = new QWidget();
        task1_page->setObjectName(QString::fromUtf8("task1_page"));
        task1_page->setStyleSheet(QString::fromUtf8("background-color:blue"));
        stackedWidget->addWidget(task1_page);
        patch_page = new QWidget();
        patch_page->setObjectName(QString::fromUtf8("patch_page"));
        patch_page->setStyleSheet(QString::fromUtf8("background-color:red"));
        stackedWidget->addWidget(patch_page);
        task2_page = new QWidget();
        task2_page->setObjectName(QString::fromUtf8("task2_page"));
        stackedWidget->addWidget(task2_page);
        q1_page = new QWidget();
        q1_page->setObjectName(QString::fromUtf8("q1_page"));
        stackedWidget->addWidget(q1_page);
        q2_page = new QWidget();
        q2_page->setObjectName(QString::fromUtf8("q2_page"));
        stackedWidget->addWidget(q2_page);
        q3_page = new QWidget();
        q3_page->setObjectName(QString::fromUtf8("q3_page"));
        stackedWidget->addWidget(q3_page);
        q4_page = new QWidget();
        q4_page->setObjectName(QString::fromUtf8("q4_page"));
        stackedWidget->addWidget(q4_page);
        wta_page = new QWidget();
        wta_page->setObjectName(QString::fromUtf8("wta_page"));
        stackedWidget->addWidget(wta_page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        intro->setText(QCoreApplication::translate("MainWindow", "Thank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 20 minutes to complete.", nullptr));
        consent_btn->setText(QCoreApplication::translate("MainWindow", "I consent", nullptr));
        outline->setText(QCoreApplication::translate("MainWindow", "This experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will first have you complete some simple tasks with these modifications turned off. Later, we will turn on these modifications and ask you to complete the same set of tasks.", nullptr));
        consent->setText(QCoreApplication::translate("MainWindow", "Do you consent to participate in this study? You may exit the experiment at any point.", nullptr));
        not_consent_btn->setText(QCoreApplication::translate("MainWindow", "I do not consent", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
