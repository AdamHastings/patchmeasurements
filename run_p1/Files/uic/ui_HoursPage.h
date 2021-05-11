/********************************************************************************
** Form generated from reading UI file 'HoursPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOURSPAGE_H
#define UI_HOURSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoursPage
{
public:

    void setupUi(QWidget *HoursPage)
    {
        if (HoursPage->objectName().isEmpty())
            HoursPage->setObjectName(QString::fromUtf8("HoursPage"));
        HoursPage->resize(400, 300);

        retranslateUi(HoursPage);

        QMetaObject::connectSlotsByName(HoursPage);
    } // setupUi

    void retranslateUi(QWidget *HoursPage)
    {
        HoursPage->setWindowTitle(QCoreApplication::translate("HoursPage", "HoursPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HoursPage: public Ui_HoursPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOURSPAGE_H
