#include "FormPage.h"
#include "Globals.h"

FormPage::FormPage(QWidget *parent)
	: QWidget(parent)
{
	QLabel* header = new QLabel(this);
	header->setGeometry(QRect(M, M, LINEWIDTH, M));
	header->setWordWrap(true);
	header->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
	header->setText("Thank you for your participation in this study. You are now finished answering questions. To receive compensation for your participation, please enter your name and mailing address below.");


}

FormPage::~FormPage()
{
}
