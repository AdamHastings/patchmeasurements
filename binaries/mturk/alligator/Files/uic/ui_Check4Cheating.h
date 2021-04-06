/********************************************************************************
** Form generated from reading UI file 'Check4Cheating.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECK4CHEATING_H
#define UI_CHECK4CHEATING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Check4Cheating
{
public:

    void setupUi(QWidget *Check4Cheating)
    {
        if (Check4Cheating->objectName().isEmpty())
            Check4Cheating->setObjectName(QString::fromUtf8("Check4Cheating"));
        Check4Cheating->resize(400, 300);

        retranslateUi(Check4Cheating);

        QMetaObject::connectSlotsByName(Check4Cheating);
    } // setupUi

    void retranslateUi(QWidget *Check4Cheating)
    {
        Check4Cheating->setWindowTitle(QCoreApplication::translate("Check4Cheating", "Check4Cheating", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Check4Cheating: public Ui_Check4Cheating {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECK4CHEATING_H
