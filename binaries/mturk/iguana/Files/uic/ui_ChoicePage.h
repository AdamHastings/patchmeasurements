/********************************************************************************
** Form generated from reading UI file 'ChoicePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOICEPAGE_H
#define UI_CHOICEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoicePage
{
public:

    void setupUi(QWidget *ChoicePage)
    {
        if (ChoicePage->objectName().isEmpty())
            ChoicePage->setObjectName(QString::fromUtf8("ChoicePage"));
        ChoicePage->resize(400, 300);

        retranslateUi(ChoicePage);

        QMetaObject::connectSlotsByName(ChoicePage);
    } // setupUi

    void retranslateUi(QWidget *ChoicePage)
    {
        ChoicePage->setWindowTitle(QCoreApplication::translate("ChoicePage", "ChoicePage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoicePage: public Ui_ChoicePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOICEPAGE_H
