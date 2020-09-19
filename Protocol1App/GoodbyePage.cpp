#include "GoodbyePage.h"
#include "Globals.h"
#include <QDebug>

GoodbyePage::GoodbyePage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 4));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setWordWrap(true);
    label->setText("Thank you for your participation. Unfortunately, you are not eligible to participate in this experiment. You may now exit this window. You may also delete this program from your computer.");
}

GoodbyePage::~GoodbyePage()
{
}
