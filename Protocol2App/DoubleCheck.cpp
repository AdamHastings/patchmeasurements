#include "DoubleCheck.h"
#include "Globals.h"

//void DoubleCheck::makeChoice() {
//    confirm_btn->setEnabled(false);
//    mistake_btn->setEnabled(false);
//}

DoubleCheck::DoubleCheck(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 3));
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setWordWrap(true);

    confirm_btn = new QPushButton(this);
    confirm_btn->setGeometry(QRect(M, M * 5, W / 2 - 2 * M, 2 * BUTTON_HEIGHT));
    confirm_btn->setText("Yes, this is correct");

    mistake_btn = new QPushButton(this);
    mistake_btn->setGeometry(QRect(M + W / 2, M * 5, W / 2 - 2 * M, 2 * BUTTON_HEIGHT));
    mistake_btn->setText("I made a mistake! Please take me\nback to the previous page.");

    done_label = new QLabel(this);
    done_label->setWordWrap(true);
    done_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    done_label->setGeometry(QRect(M * 2, M * 7, LINEWIDTH - 2 * M, M * 3));

   /* connect(this->confirm_btn, &QPushButton::clicked, this, &DoubleCheck::makeChoice);
    connect(this->mistake_btn, &QPushButton::clicked, this, &DoubleCheck::makeChoice);*/
}

DoubleCheck::~DoubleCheck()
{
}
