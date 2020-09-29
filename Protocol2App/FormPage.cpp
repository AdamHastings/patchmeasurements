#include "FormPage.h"

void FormPage::enableContinueBtn(const QString& text) {
	this->continue_btn->setEnabled(true);
}

FormPage::FormPage(QWidget *parent)
	: QWidget(parent)
{
	label = new QLabel(this);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	label->setGeometry(QRect(M, M, LINEWIDTH, M * 4));
	label->setText("Please enter your UNI below:");

	line = new QLineEdit(this);
	line->setGeometry(W / 2 - BUTTON_WIDTH/2, M * 5, BUTTON_WIDTH, BUTTON_HEIGHT);

	continue_btn = new QPushButton(this);
	continue_btn->setText("Continue");
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
#ifndef QT_NO_DEBUG
	continue_btn->setEnabled(false);
#endif


	connect(this->line, &QLineEdit::textChanged, this, &FormPage::enableContinueBtn);
}

FormPage::~FormPage()
{
}
