/********************************************************************************
** Form generated from reading UI file 'RankPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKPAGE_H
#define UI_RANKPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RankPage
{
public:

    void setupUi(QWidget *RankPage)
    {
        if (RankPage->objectName().isEmpty())
            RankPage->setObjectName(QString::fromUtf8("RankPage"));
        RankPage->resize(400, 300);

        retranslateUi(RankPage);

        QMetaObject::connectSlotsByName(RankPage);
    } // setupUi

    void retranslateUi(QWidget *RankPage)
    {
        RankPage->setWindowTitle(QCoreApplication::translate("RankPage", "RankPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankPage: public Ui_RankPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKPAGE_H
