/********************************************************************************
** Form generated from reading UI file 'DoubleCheck.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLECHECK_H
#define UI_DOUBLECHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleCheck
{
public:

    void setupUi(QWidget *DoubleCheck)
    {
        if (DoubleCheck->objectName().isEmpty())
            DoubleCheck->setObjectName(QString::fromUtf8("DoubleCheck"));
        DoubleCheck->resize(400, 300);

        retranslateUi(DoubleCheck);

        QMetaObject::connectSlotsByName(DoubleCheck);
    } // setupUi

    void retranslateUi(QWidget *DoubleCheck)
    {
        DoubleCheck->setWindowTitle(QCoreApplication::translate("DoubleCheck", "DoubleCheck", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoubleCheck: public Ui_DoubleCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLECHECK_H
