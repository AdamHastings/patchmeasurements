/********************************************************************************
** Form generated from reading UI file 'ComparePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPAREPAGE_H
#define UI_COMPAREPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComparePage
{
public:

    void setupUi(QWidget *ComparePage)
    {
        if (ComparePage->objectName().isEmpty())
            ComparePage->setObjectName(QString::fromUtf8("ComparePage"));
        ComparePage->resize(400, 300);

        retranslateUi(ComparePage);

        QMetaObject::connectSlotsByName(ComparePage);
    } // setupUi

    void retranslateUi(QWidget *ComparePage)
    {
        ComparePage->setWindowTitle(QCoreApplication::translate("ComparePage", "ComparePage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComparePage: public Ui_ComparePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPAREPAGE_H
