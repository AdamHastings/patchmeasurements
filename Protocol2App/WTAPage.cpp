#include "WTAPage.h"
#include "Globals.h"
#include "DropBox.h"
#include "RegistryUtils.h"

#include <QDebug>

void WTAPage::firstOffer() {
    // TODO wording is funny...
   /* header->setText("We are offering you the opportunity to slow down your computer by " + QString::number(SLOWDOWN) + "% in exchange for $" + QString::number(OFFER) + " a day for up to 30 days. You will be given this choice every day. Would you like to accept this offer?");

    accept->setText("Please pay me $" + QString::number(OFFER) + " in exchange for  slowing down my computer by " + QString::number(SLOWDOWN) + "% for 24 hours.");

    decline->setText("No thanks, I'd rather not");*/
}

WTAPage::WTAPage(QWidget* parent)
    : QWidget(parent)
{
    header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M * 5));
    header->setAlignment(Qt::AlignJustify | Qt::AlignTop);
    header->setWordWrap(true);
    //header->setText("Your computer is being slowed down by " + QString::number(SLOWDOWN) + "%. You are now being offered the chance to either restore your computer to full performance, or to accept $" + QString::number(OFFER) + " in exchange for continuing to use a slowed down version of your computer. Please make your choice below:");

    accept = new QRadioButton(this);
    accept->setGeometry(QRect(3*M, 5.5 * M, W - 6*M, M));
    //accept->setText("Please pay me $" + QString::number(OFFER) + " in exchange for continuing letting this program\ncontinue to slow down my computer by " + QString::number(SLOWDOWN) + "% for another 24 hours.");
    
    decline = new QRadioButton(this);
    decline->setGeometry(QRect(3*M, 6.5 * M, W - 6*M, M));
    //decline->setText("Please restore my computer to full speed. I understand that\nthis forfeits all future earnings I may gain from this experiment.");
    
    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH/2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
#ifndef QT_NO_DEBUG
    continue_btn->setEnabled(false);
#endif

    connect(this->accept, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->decline, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
}

WTAPage::~WTAPage()
{
}

void WTAPage::resetPage(int days) {
    if (days == TOTAL_DAYS) {
        header->setText("You will now make a choice that will have real-world consequences and will directly affect how much money you earn from this experiment, so please read this section carefully. We are offering you the opportunity to slow down your computer by " + QString::number(SLOWDOWN) + "% for 24 hours in exchange for $" + QString::number(OFFER) + ". If you do not accept the money, your computer will not be slowed down and you will be removed from the experiment. You will only earn the baseline compensation of $5. However, if you accept the money, your computer will run slower for 24 hours, which may cause your device to feel slower and less responsive. After 24 hours, you will be asked if you would like to continue slowing down your computer for another 24 hours in exchange for another $" + QString::number(OFFER) + ". This process continues until either you decline to accept the money, or until " + QString::number(TOTAL_DAYS) + " days have elapsed since the start of this experiment. If you choose to slow down your computer for the full 30 days, you will earn $5 + (" + QString::number(TOTAL_DAYS) + " x $" + QString::number(OFFER) + ") = $" + QString::number(5 + (OFFER * TOTAL_DAYS)) + ".\n\nWould you like to accept this offer?");

        accept->setText("Please pay me $" + QString::number(OFFER) + " in exchange for  slowing down my computer by " + QString::number(SLOWDOWN) + "% for 24 hours.");

        decline->setText("No thanks, I'd rather not");
    }
    else if (days < TOTAL_DAYS) {

        accept->setGeometry(QRect(3 * M, 4 * M, W - 6 * M, M));
        accept->setText("Please pay me $" + QString::number(OFFER) + " in exchange for continuing letting this program\ncontinue to slow down my computer by " + QString::number(SLOWDOWN) + "% for another 24 hours.");

        decline->setGeometry(QRect(3 * M, 5.5 * M, W - 6 * M, M));
        decline->setText("Please restore my computer to full speed. I understand that\nthis forfeits all future earnings I may gain from this experiment.");

        if (days != 1) {
            header->setText("Your computer has been slowed for the last 24 hours down by " + QString::number(SLOWDOWN) + "% in exchange for " + QString::number(OFFER) + ". You are now being offered the chance to either restore your computer to full performance, or to accept $" + QString::number(OFFER) + " in exchange for slowing down your computer for another 24 hours. If you choose to restore your computer's performance now, your final earnings from this experiment will be $5 + (" + QString::number(TOTAL_DAYS - days) + " x $" + QString::number(OFFER) + ") = $" + QString::number(5 + (OFFER * (TOTAL_DAYS - days))) + ". However, if you choose to remain in this experiment by keeping your computer slowed down for the remaining " + QString::number(days) + " days, you can earn an additional $(" + QString::number(days) + " x " + QString::number(OFFER) + ") = $" + QString::number(OFFER*days) + ".\n\nPlease make your choice below:");
        }
        else {
            header->setText("Your computer has been slowed for the last 24 hours down by " + QString::number(SLOWDOWN) + "% in exchange for " + QString::number(OFFER) + ". You are now being offered the chance to either restore your computer to full performance, or to accept $" + QString::number(OFFER) + " in exchange for slowing down your computer for another 24 hours. If you choose to restore your computer's performance now, your final earnings from this experiment will be $5 + (" + QString::number(TOTAL_DAYS - days) + " x $" + QString::number(OFFER) + ") = $" + QString::number(5 + (OFFER * (TOTAL_DAYS - days))) + ". However, if you choose to remain in this experiment by keeping your computer slowed down for the remaining " + QString::number(days) + " day, you can earn an additional $(" + QString::number(days) + " x " + QString::number(OFFER) + ") = $" + QString::number(OFFER * days) + ".\n\nPlease make your choice below:");
        }
    }
}
