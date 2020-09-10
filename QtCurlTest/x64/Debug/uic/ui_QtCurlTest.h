/********************************************************************************
** Form generated from reading UI file 'QtCurlTest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCURLTEST_H
#define UI_QTCURLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtCurlTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtCurlTestClass)
    {
        if (QtCurlTestClass->objectName().isEmpty())
            QtCurlTestClass->setObjectName(QString::fromUtf8("QtCurlTestClass"));
        QtCurlTestClass->resize(600, 400);
        menuBar = new QMenuBar(QtCurlTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtCurlTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtCurlTestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtCurlTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtCurlTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtCurlTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtCurlTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtCurlTestClass->setStatusBar(statusBar);

        retranslateUi(QtCurlTestClass);

        QMetaObject::connectSlotsByName(QtCurlTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtCurlTestClass)
    {
        QtCurlTestClass->setWindowTitle(QCoreApplication::translate("QtCurlTestClass", "QtCurlTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtCurlTestClass: public Ui_QtCurlTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCURLTEST_H
