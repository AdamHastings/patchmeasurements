#include "StartPage.h"
#include "Globals.h"
#include <QLabel>

void StartPage::checkIfContinue() {
    if (consent_btn->isChecked() || not_consent_btn->isChecked()) {
        continue_btn->setEnabled(true);
    }
    else {
        continue_btn->setEnabled(false);
    }
}

StartPage::StartPage(QWidget* parent)
    : QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 4));
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setWordWrap(true);
    label->setText("Thank you for participating in this experiment. This experiment is designed to test out some computer features we are prototyping. We will have you complete some simple tasks followed by a brief survey. Participation will take about 20 to 30 minutes. Participation will help the researchers better understand the economics of the computer industry.\n\nDo you consent to participate in this experiment?");

    consent_btn = new QRadioButton(this);
    consent_btn->setGeometry(QRect(2 * M, M * 5, LINEWIDTH - 2 * M, M));
    consent_btn->setText("I consent");

    not_consent_btn = new QRadioButton(this);
    not_consent_btn->setGeometry(QRect(2 * M, M * 6, LINEWIDTH - 2 * M, M));
    not_consent_btn->setText("I do not consent");

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
    continue_btn->setEnabled(false);

    //stackedWidget->addWidget(start_page);
    connect(consent_btn, &QRadioButton::clicked, this, &StartPage::checkIfContinue);
    connect(not_consent_btn, &QRadioButton::clicked, this, &StartPage::checkIfContinue);
}

StartPage::~StartPage()
{
}
