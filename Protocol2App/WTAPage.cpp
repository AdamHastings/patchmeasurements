#include "WTAPage.h"
#include "Globals.h"

WTAPage::WTAPage(QWidget* parent)
    : QWidget(parent)
{
    header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M * 2));
    header->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    header->setWordWrap(true);
    header->setText("Your computer has been slowed down by " + QString::number(SLOWDOWN) + "%. You are now being offered the chance to either restore your computer to full performance, or to accept $" + QString::number(OFFER) + " in exchange for continuing to use a slowed down version of your computer. Please make your choice below:");

    accept = new QRadioButton(this);
    accept->setGeometry(QRect(3*M, 3 * M, W - 6*M, M));
    accept->setText("Please pay me $" + QString::number(OFFER) + " in exchange for continuing letting this program\ncontinue to slow down my computer by " + QString::number(SLOWDOWN) + "% for another 24 hours.");
    
    decline = new QRadioButton(this);
    decline->setGeometry(QRect(3*M, 5 * M, W - 6*M, M));
    decline->setText("Please restore my computer to full speed. I understand that\nthis forfeits all future earnings I may gain from this experiment.");
    

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
