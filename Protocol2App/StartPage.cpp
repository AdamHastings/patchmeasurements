#include "StartPage.h"
#include "Globals.h"
#include <QLabel>

StartPage::StartPage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 6));
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setWordWrap(true);

    consent_btn = new QPushButton(this);
    consent_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH - M, M * 7, BUTTON_WIDTH, BUTTON_HEIGHT));
    consent_btn->setText("I consent");

    not_consent_btn = new QPushButton(this);
    not_consent_btn->setGeometry(QRect(W / 2 + M, M * 7, BUTTON_WIDTH, BUTTON_HEIGHT));
    not_consent_btn->setText("I do not consent");

    //stackedWidget->addWidget(start_page);

    label->setText("Thank you for participating in this experiment. This experiment is designed to study how much you value the performance on your computer. In a moment, you will be asked to make a choice between money and your computer's performance. If you accept the money, you will be given the opportunity to continue making this tradeoff (money in exchange for lower computer performance) every day for up to thirty days. Even if you accept the money, you can still back out of this experiment at any time and restore your computer to full performance without jeoapardizing previous earnings.\n\nDo you consent to participate in this experiment?");
}

StartPage::~StartPage()
{
}
