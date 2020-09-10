/********************************************************************************
** Form generated from reading UI file 'PostRequest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTREQUEST_H
#define UI_POSTREQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostRequestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PostRequestClass)
    {
        if (PostRequestClass->objectName().isEmpty())
            PostRequestClass->setObjectName(QString::fromUtf8("PostRequestClass"));
        PostRequestClass->resize(600, 400);
        menuBar = new QMenuBar(PostRequestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        PostRequestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PostRequestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PostRequestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PostRequestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PostRequestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PostRequestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PostRequestClass->setStatusBar(statusBar);

        retranslateUi(PostRequestClass);

        QMetaObject::connectSlotsByName(PostRequestClass);
    } // setupUi

    void retranslateUi(QMainWindow *PostRequestClass)
    {
        PostRequestClass->setWindowTitle(QCoreApplication::translate("PostRequestClass", "PostRequest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostRequestClass: public Ui_PostRequestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTREQUEST_H
