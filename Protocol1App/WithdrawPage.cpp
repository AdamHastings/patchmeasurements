#include "WithdrawPage.h"
#include "Globals.h"

WithdrawPage::WithdrawPage(QWidget *parent)
	: QWidget(parent)
{

	label = new QLabel(this);
    label->setGeometry(M, M, LINEWIDTH, 2*M);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setWordWrap(true);
    label->setText("Are you sure you want to withdraw? If you confirm your intent to withdraw below, you will receive no compensation for your participation in this experiment. If you withdraw, your survey responses will not be sent to the researchers and will not be used in any future studies.");

    /*withdraw_btn = new QPushButton(this);
    withdraw_btn->setGeometry(W / 2 - 6 * M, M * 4, 5 * M, M);
    withdraw_btn->setText("Yes, I am sure. Please withdraw me\nfrom this experiment and do not contact me further, including for compensation");

    dont_withdraw_btn = new QPushButton(this);
    dont_withdraw_btn->setGeometry(W / 2 + M, M * 4, 5 * M, M);
    dont_withdraw_btn->setText("Oops, I've made a mistake. Please do NOT withdraw me from\nthis experiment so that I may be compensated for my participation");*/

    withdraw_btn = new QRadioButton(this);
    withdraw_btn->setGeometry(2 * M, 3 * M, LINEWIDTH - 2 * M, 2 * M);
    withdraw_btn->setText("Yes, I am sure. Please withdraw me from this experiment and do not contact me further.\nI understand that this means I will not be compensated for participating in this study.");

    dont_withdraw_btn = new QRadioButton(this);
    dont_withdraw_btn->setGeometry(2 * M, 4.5 * M, LINEWIDTH - 2 * M, 2 * M);
    dont_withdraw_btn->setText("Oops, I've made a mistake. Please take me back to the previous page.");

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(W / 2 - BUTTON_WIDTH / 2, M * 7, BUTTON_WIDTH, BUTTON_HEIGHT);
    continue_btn->setText("Continue");
//#ifdef QT_NO_DEBUG
    continue_btn->setEnabled(false);
//#endif // QT_NO_DEBUG

    connect(this->withdraw_btn, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);

    connect(this->dont_withdraw_btn, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);

    withdrawn = new QLabel(this);
    withdrawn->setGeometry(M, M * 8, LINEWIDTH, M);
    withdrawn->setWordWrap(true);
    withdrawn->setText("You have withdrawn from this experiment. Your survery answers will not be used in any way by the researchers. You may exit this window and delete this program from your device.");
    withdrawn->setVisible(false);

}

WithdrawPage::~WithdrawPage()
{
}

void WithdrawPage::Withdraw() {
    continue_btn->setEnabled(false);
    withdraw_btn->setEnabled(false);
    dont_withdraw_btn->setEnabled(false);
    withdrawn->setVisible(true);
    
}
