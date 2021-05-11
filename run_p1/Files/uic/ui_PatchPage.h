/********************************************************************************
** Form generated from reading UI file 'PatchPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATCHPAGE_H
#define UI_PATCHPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatchPage
{
public:

    void setupUi(QWidget *PatchPage)
    {
        if (PatchPage->objectName().isEmpty())
            PatchPage->setObjectName(QString::fromUtf8("PatchPage"));
        PatchPage->resize(400, 300);

        retranslateUi(PatchPage);

        QMetaObject::connectSlotsByName(PatchPage);
    } // setupUi

    void retranslateUi(QWidget *PatchPage)
    {
        PatchPage->setWindowTitle(QCoreApplication::translate("PatchPage", "PatchPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatchPage: public Ui_PatchPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATCHPAGE_H
