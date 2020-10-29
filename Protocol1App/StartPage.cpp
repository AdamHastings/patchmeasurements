#include "StartPage.h"
#include "Globals.h"

StartPage::StartPage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(MARGIN, MARGIN, LINEWIDTH, MARGIN * 6));
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setWordWrap(true);

    consent_btn = new QPushButton(this);
    consent_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH - M, M * 7, BUTTON_WIDTH, BUTTON_HEIGHT));
    consent_btn->setText("I consent");

    not_consent_btn = new QPushButton(this);
    not_consent_btn->setGeometry(QRect(W / 2 + M, M * 7, BUTTON_WIDTH, BUTTON_HEIGHT));
    not_consent_btn->setText("I do not consent");

    label->setText("Thank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment will take about 20 minutes to complete.\n\nThis experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will have you complete some simple tasks under a variety of different circumstances. After you complete the tasks, we will ask you a few questions about your experience.\n\nDo you consent to participate in this study? You may exit the experiment at any point.");

    // TODO can we tell them they have to finish the experiment?
}

StartPage::~StartPage()
{
}
