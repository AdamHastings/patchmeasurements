#include "ExitPage.h"
#include "Globals.h"

ExitPage::ExitPage(QWidget *parent)
	: QWidget(parent)
{
	label = new QLabel(this);
	label->setGeometry(QRect(2*M, M, LINEWIDTH-2*M, M * 6));
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label->setWordWrap(true);
}

ExitPage::~ExitPage()
{
}