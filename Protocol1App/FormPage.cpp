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

	name = new QLabel(this);
	name->setGeometry(2*M, 3*M, 2*M, BUTTON_HEIGHT);
	name->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	name->setText("Name  ");
	line_name = new QLineEdit(this);
	line_name->setGeometry(4 * M, 3 * M, 4*M, BUTTON_HEIGHT);

	uni = new QLabel(this);
	uni->setGeometry(8 * M, 3 * M, 2 * M, BUTTON_HEIGHT);
	uni->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	uni->setText("UNI  ");
	line_uni = new QLineEdit(this);
	line_uni->setGeometry(10 * M, 3 * M, 4 * M, BUTTON_HEIGHT);

	address = new QLabel(this);
	address->setGeometry(2 * M, 5 * M, 2 * M, BUTTON_HEIGHT);
	address->setText("Address  ");
	address->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	line_address = new QLineEdit(this);
	line_address->setGeometry(4 * M, 5 * M, 10 * M, BUTTON_HEIGHT);

	city = new QLabel(this);
	city->setGeometry(2 * M, 6 * M, 2 * M, BUTTON_HEIGHT);
	city->setText("City  ");
	city->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	line_city = new QLineEdit(this);
	line_city->setGeometry(4 * M, 6 * M, 2 * M, BUTTON_HEIGHT);

	state = new QLabel(this);
	state->setGeometry(6 * M, 6 * M, 2 * M, BUTTON_HEIGHT);
	state->setText("State  ");
	state->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	line_state = new QLineEdit(this);
	line_state->setGeometry(8 * M, 6 * M, 2 * M, BUTTON_HEIGHT);

	zip = new QLabel(this);
	zip->setGeometry(10 * M, 6 * M, 2 * M, BUTTON_HEIGHT);
	zip->setText("Zip  ");
	zip->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	line_zip = new QLineEdit(this);
	line_zip->setGeometry(12 * M, 6 * M, 2 * M, BUTTON_HEIGHT);

	

	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
}

FormPage::~FormPage()
{
}
