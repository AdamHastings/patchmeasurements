/********************************************************************************
** Form generated from reading UI file 'RegistryEditPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRYEDITPAGE_H
#define UI_REGISTRYEDITPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistryEditPage
{
public:

    void setupUi(QWidget *RegistryEditPage)
    {
        if (RegistryEditPage->objectName().isEmpty())
            RegistryEditPage->setObjectName(QString::fromUtf8("RegistryEditPage"));
        RegistryEditPage->resize(400, 300);

        retranslateUi(RegistryEditPage);

        QMetaObject::connectSlotsByName(RegistryEditPage);
    } // setupUi

    void retranslateUi(QWidget *RegistryEditPage)
    {
        RegistryEditPage->setWindowTitle(QCoreApplication::translate("RegistryEditPage", "RegistryEditPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistryEditPage: public Ui_RegistryEditPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRYEDITPAGE_H
