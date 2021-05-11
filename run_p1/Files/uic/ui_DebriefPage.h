/********************************************************************************
** Form generated from reading UI file 'DebriefPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBRIEFPAGE_H
#define UI_DEBRIEFPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebriefPage
{
public:

    void setupUi(QWidget *DebriefPage)
    {
        if (DebriefPage->objectName().isEmpty())
            DebriefPage->setObjectName(QString::fromUtf8("DebriefPage"));
        DebriefPage->resize(400, 300);

        retranslateUi(DebriefPage);

        QMetaObject::connectSlotsByName(DebriefPage);
    } // setupUi

    void retranslateUi(QWidget *DebriefPage)
    {
        DebriefPage->setWindowTitle(QCoreApplication::translate("DebriefPage", "DebriefPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebriefPage: public Ui_DebriefPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBRIEFPAGE_H
