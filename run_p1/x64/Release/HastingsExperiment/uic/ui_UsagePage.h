/********************************************************************************
** Form generated from reading UI file 'UsagePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USAGEPAGE_H
#define UI_USAGEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsagePage
{
public:

    void setupUi(QWidget *UsagePage)
    {
        if (UsagePage->objectName().isEmpty())
            UsagePage->setObjectName(QString::fromUtf8("UsagePage"));
        UsagePage->resize(400, 300);

        retranslateUi(UsagePage);

        QMetaObject::connectSlotsByName(UsagePage);
    } // setupUi

    void retranslateUi(QWidget *UsagePage)
    {
        UsagePage->setWindowTitle(QCoreApplication::translate("UsagePage", "UsagePage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsagePage: public Ui_UsagePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USAGEPAGE_H
