/********************************************************************************
** Form generated from reading UI file 'Protocol2App.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOCOL2APP_H
#define UI_PROTOCOL2APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Protocol2AppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Protocol2AppClass)
    {
        if (Protocol2AppClass->objectName().isEmpty())
            Protocol2AppClass->setObjectName(QString::fromUtf8("Protocol2AppClass"));
        Protocol2AppClass->resize(600, 400);
        menuBar = new QMenuBar(Protocol2AppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Protocol2AppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Protocol2AppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Protocol2AppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Protocol2AppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Protocol2AppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Protocol2AppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Protocol2AppClass->setStatusBar(statusBar);

        retranslateUi(Protocol2AppClass);

        QMetaObject::connectSlotsByName(Protocol2AppClass);
    } // setupUi

    void retranslateUi(QMainWindow *Protocol2AppClass)
    {
        Protocol2AppClass->setWindowTitle(QCoreApplication::translate("Protocol2AppClass", "Protocol2App", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Protocol2AppClass: public Ui_Protocol2AppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOCOL2APP_H
