/********************************************************************************
** Form generated from reading UI file 'SurveyPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURVEYPAGE_H
#define UI_SURVEYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SurveyPage
{
public:

    void setupUi(QWidget *SurveyPage)
    {
        if (SurveyPage->objectName().isEmpty())
            SurveyPage->setObjectName(QString::fromUtf8("SurveyPage"));
        SurveyPage->resize(400, 300);

        retranslateUi(SurveyPage);

        QMetaObject::connectSlotsByName(SurveyPage);
    } // setupUi

    void retranslateUi(QWidget *SurveyPage)
    {
        SurveyPage->setWindowTitle(QCoreApplication::translate("SurveyPage", "SurveyPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SurveyPage: public Ui_SurveyPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURVEYPAGE_H
