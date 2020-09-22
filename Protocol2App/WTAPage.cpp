#include "WTAPage.h"
#include "Globals.h"

WTAPage::WTAPage(QWidget* parent)
    : QWidget(parent)
{
    header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M * 3));
    header->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    header->setWordWrap(true);
    header->setText("Your computer has been slowed down by " + QString::number(SLOWDOWN) + "%. You are now being offered the chance to either restore your computer to full performance, or to accept $" + QString::number(OFFER) + " in exchange for continuing to use a slowed down version of your computer. Please make your choice below:");


    /*offer_label = new QLabel(this);
    offer_label->setGeometry(QRect(0, M * 3, W, M * 2));
    offer_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    QFont font = QFont();
    font.setBold(true);
    font.setPointSize(30);
    offer_label->setFont(font);*/

    QLabel* disclaimer = new QLabel(this);
    disclaimer->setGeometry(QRect(M, M * 5, W - (2 * M), M * 3));
    disclaimer->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    disclaimer->setWordWrap(true);
    disclaimer->setText("(This is for your current computer only and does not apply to any future computers you may buy.)");
    // wta_disclamer_label->setText("Note: ");
    // Would you be willing to slow down your computer for
    // Avoid "permanent"


    yes_btn = new QPushButton(this);
    yes_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH - M, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    yes_btn->setText("Yes");

    no_btn = new QPushButton(this);
    no_btn->setGeometry(QRect(W / 2 + M, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    no_btn->setText("No");
}

WTAPage::~WTAPage()
{
}

void WTAPage::updateOffer(int new_offer) {
    offer_label->setText("$" + QString::number(new_offer) + "?");
}
