#include "GoodbyePage.h"
#include "Globals.h"
#include <QDebug>

GoodbyePage::GoodbyePage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    //label->setGeometry(QRect(20, 20, 500, 500));
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 4));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setWordWrap(true);
    label->setText("Thank you for your participation. You may now exit this window.");
}

GoodbyePage::~GoodbyePage()
{
}
