/********************************************************************************
** Form generated from reading UI file 'WTAPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WTAPAGE_H
#define UI_WTAPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WTAPage
{
public:

    void setupUi(QWidget *WTAPage)
    {
        if (WTAPage->objectName().isEmpty())
            WTAPage->setObjectName(QString::fromUtf8("WTAPage"));
        WTAPage->resize(400, 300);

        retranslateUi(WTAPage);

        QMetaObject::connectSlotsByName(WTAPage);
    } // setupUi

    void retranslateUi(QWidget *WTAPage)
    {
        WTAPage->setWindowTitle(QCoreApplication::translate("WTAPage", "WTAPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WTAPage: public Ui_WTAPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WTAPAGE_H
