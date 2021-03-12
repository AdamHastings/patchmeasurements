/********************************************************************************
** Form generated from reading UI file 'FormPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPAGE_H
#define UI_FORMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPage
{
public:

    void setupUi(QWidget *FormPage)
    {
        if (FormPage->objectName().isEmpty())
            FormPage->setObjectName(QString::fromUtf8("FormPage"));
        FormPage->resize(400, 300);

        retranslateUi(FormPage);

        QMetaObject::connectSlotsByName(FormPage);
    } // setupUi

    void retranslateUi(QWidget *FormPage)
    {
        FormPage->setWindowTitle(QCoreApplication::translate("FormPage", "FormPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPage: public Ui_FormPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPAGE_H
