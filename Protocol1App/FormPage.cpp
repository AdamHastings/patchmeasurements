#include "FormPage.h"
#include "Globals.h"

#include <algorithm>

void FormPage::updateContinueBtn(const QString &text) {
	if (line_uni->text() != "") {
		uni_str = line_uni->text().toStdString();
		std::replace(uni_str.begin(), uni_str.end(), ',', ' ');
		continue_btn->setEnabled(true);
	}
}

void FormPage::makeConnections() {
	connect(this->line_uni, &QLineEdit::textEdited, this, &FormPage::updateContinueBtn);
}

FormPage::FormPage(QWidget *parent)
	: QWidget(parent)
{

	// setup page layout
	header = new QLabel(this);
	header->setGeometry(QRect(M, M, LINEWIDTH, 2*M));
	header->setWordWrap(true);
	header->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
	header->setText("Please enter your Mechanical Turk ID below:");

	uni = new QLabel(this);
	uni->setGeometry(W/2 - (3 * M), 3 * M, 2 * M, BUTTON_HEIGHT);
	uni->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	uni->setText("Worker ID:  ");
	line_uni = new QLineEdit(this);
	line_uni->setGeometry(W/2-M, 3 * M, 4 * M, BUTTON_HEIGHT);
	

	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
#ifdef QT_NO_DEBUG
	continue_btn->setEnabled(false);
#endif

	makeConnections();
}

FormPage::~FormPage()
{
}
