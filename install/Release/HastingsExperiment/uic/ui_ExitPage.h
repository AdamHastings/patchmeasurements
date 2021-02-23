/********************************************************************************
** Form generated from reading UI file 'ExitPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITPAGE_H
#define UI_EXITPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExitPage
{
public:

    void setupUi(QWidget *ExitPage)
    {
        if (ExitPage->objectName().isEmpty())
            ExitPage->setObjectName(QString::fromUtf8("ExitPage"));
        ExitPage->resize(400, 300);

        retranslateUi(ExitPage);

        QMetaObject::connectSlotsByName(ExitPage);
    } // setupUi

    void retranslateUi(QWidget *ExitPage)
    {
        ExitPage->setWindowTitle(QCoreApplication::translate("ExitPage", "ExitPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExitPage: public Ui_ExitPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITPAGE_H
