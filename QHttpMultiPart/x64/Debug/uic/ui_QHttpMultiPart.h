/********************************************************************************
** Form generated from reading UI file 'QHttpMultiPart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QHTTPMULTIPART_H
#define UI_QHTTPMULTIPART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QHttpMultiPartClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QHttpMultiPartClass)
    {
        if (QHttpMultiPartClass->objectName().isEmpty())
            QHttpMultiPartClass->setObjectName(QString::fromUtf8("QHttpMultiPartClass"));
        QHttpMultiPartClass->resize(600, 400);
        menuBar = new QMenuBar(QHttpMultiPartClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QHttpMultiPartClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QHttpMultiPartClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QHttpMultiPartClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QHttpMultiPartClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QHttpMultiPartClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QHttpMultiPartClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QHttpMultiPartClass->setStatusBar(statusBar);

        retranslateUi(QHttpMultiPartClass);

        QMetaObject::connectSlotsByName(QHttpMultiPartClass);
    } // setupUi

    void retranslateUi(QMainWindow *QHttpMultiPartClass)
    {
        QHttpMultiPartClass->setWindowTitle(QCoreApplication::translate("QHttpMultiPartClass", "QHttpMultiPart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QHttpMultiPartClass: public Ui_QHttpMultiPartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QHTTPMULTIPART_H
