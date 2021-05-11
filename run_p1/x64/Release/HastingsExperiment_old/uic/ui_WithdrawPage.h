/********************************************************************************
** Form generated from reading UI file 'WithdrawPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWPAGE_H
#define UI_WITHDRAWPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WithdrawPage
{
public:

    void setupUi(QWidget *WithdrawPage)
    {
        if (WithdrawPage->objectName().isEmpty())
            WithdrawPage->setObjectName(QString::fromUtf8("WithdrawPage"));
        WithdrawPage->resize(400, 300);

        retranslateUi(WithdrawPage);

        QMetaObject::connectSlotsByName(WithdrawPage);
    } // setupUi

    void retranslateUi(QWidget *WithdrawPage)
    {
        WithdrawPage->setWindowTitle(QCoreApplication::translate("WithdrawPage", "WithdrawPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawPage: public Ui_WithdrawPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWPAGE_H
