#include "FormPage.h"
#include "Globals.h"

FormPage::FormPage(QWidget *parent)
	: QWidget(parent)
{
	header = new QLabel(this);
	header->setGeometry(QRect(M, M, LINEWIDTH, M));
	header->setWordWrap(true);
	header->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
	header->setText("Thank you for your participation in this study. You are now finished answering questions. To receive compensation for your participation, please enter your name and mailing address below.");

	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
}

FormPage::~FormPage()
{
}
