#include "GoodbyePage.h"
#include <QRect>

GoodbyePage::GoodbyePage(QWidget* parent)
	: QWidget(parent)
{
	label = new QLabel(this);
	label->setGeomtery(QRect(10, 10, 100, 50));
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label->setWordWrap(true);
	label->setText("Thank you for your participation. You may now exit this window.");
}

GoodbyePage::~GoodbyePage()
{

}