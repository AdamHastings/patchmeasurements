/********************************************************************************
** Form generated from reading UI file 'SingleChoicePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLECHOICEPAGE_H
#define UI_SINGLECHOICEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleChoicePage
{
public:

    void setupUi(QWidget *SingleChoicePage)
    {
        if (SingleChoicePage->objectName().isEmpty())
            SingleChoicePage->setObjectName(QString::fromUtf8("SingleChoicePage"));
        SingleChoicePage->resize(400, 300);

        retranslateUi(SingleChoicePage);

        QMetaObject::connectSlotsByName(SingleChoicePage);
    } // setupUi

    void retranslateUi(QWidget *SingleChoicePage)
    {
        SingleChoicePage->setWindowTitle(QCoreApplication::translate("SingleChoicePage", "SingleChoicePage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleChoicePage: public Ui_SingleChoicePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLECHOICEPAGE_H
