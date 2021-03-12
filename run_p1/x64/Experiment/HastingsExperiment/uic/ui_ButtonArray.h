/********************************************************************************
** Form generated from reading UI file 'ButtonArray.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONARRAY_H
#define UI_BUTTONARRAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ButtonArray
{
public:

    void setupUi(QWidget *ButtonArray)
    {
        if (ButtonArray->objectName().isEmpty())
            ButtonArray->setObjectName(QString::fromUtf8("ButtonArray"));
        ButtonArray->resize(400, 300);

        retranslateUi(ButtonArray);

        QMetaObject::connectSlotsByName(ButtonArray);
    } // setupUi

    void retranslateUi(QWidget *ButtonArray)
    {
        ButtonArray->setWindowTitle(QCoreApplication::translate("ButtonArray", "ButtonArray", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ButtonArray: public Ui_ButtonArray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONARRAY_H
