#include "GoodbyePage.h"

GoodbyePage::GoodbyePage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(20, 20, 100, 20));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setWordWrap(true);
    label->setText("Thank you for your participation. You may now exit this window.");
}

GoodbyePage::~GoodbyePage()
{
}
