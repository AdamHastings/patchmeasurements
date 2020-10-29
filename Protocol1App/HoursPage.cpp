#include "HoursPage.h"
#include "Globals.h"

HoursPage::HoursPage(QWidget *parent)
	: QWidget(parent)
{

	label = new QLabel(this);
	label->setText("How many hours a week do you typically spend on this computer?");
	label->setAlignment(Qt::AlignCenter);
	label->setGeometry(M, M, LINEWIDTH, M);

	spin = new QSpinBox(this);
	spin->setMinimum(0);
	spin->setMaximum(24 * 7);
	spin->setGeometry(W / 2 - M, M * 5, 2 * M, M);

	continue_btn = new QPushButton(this);
	continue_btn->setText("Continue");
	continue_btn->setGeometry(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT);
}

HoursPage::~HoursPage()
{
}
