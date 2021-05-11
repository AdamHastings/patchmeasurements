/********************************************************************************
** Form generated from reading UI file 'GoodbyePage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODBYEPAGE_H
#define UI_GOODBYEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoodbyePage
{
public:

    void setupUi(QWidget *GoodbyePage)
    {
        if (GoodbyePage->objectName().isEmpty())
            GoodbyePage->setObjectName(QString::fromUtf8("GoodbyePage"));
        GoodbyePage->resize(400, 300);

        retranslateUi(GoodbyePage);

        QMetaObject::connectSlotsByName(GoodbyePage);
    } // setupUi

    void retranslateUi(QWidget *GoodbyePage)
    {
        GoodbyePage->setWindowTitle(QCoreApplication::translate("GoodbyePage", "GoodbyePage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoodbyePage: public Ui_GoodbyePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODBYEPAGE_H
