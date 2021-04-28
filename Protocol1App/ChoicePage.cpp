#include "ChoicePage.h"
#include "Globals.h"




QRadioButton* ImproveChoicePage::perf_btn;
QRadioButton* ImproveChoicePage::sec_btn;

void ImproveChoicePage::checkContinue() {
	if (perf_btn->isChecked() || sec_btn->isChecked()) {
		continue_btn->setEnabled(true);
	}
	else {
		continue_btn->setEnabled(false);
	}
}

ImproveChoicePage::ImproveChoicePage(QWidget* parent)
	: QWidget(parent)
{

	label = new QLabel(this);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignJustify);
	label->setGeometry(M, 2 * M, LINEWIDTH, 4 * M);
	label->setText("If you could choose between improving your computer's performance or improving your computer's security, which would you choose?");


	perf_btn = new QRadioButton(this);
	perf_btn->setGeometry(2 * M, M * 4, LINEWIDTH - 2 * M, BUTTON_HEIGHT);
	perf_btn->setText("I would improve my computer's performance");

	sec_btn = new QRadioButton(this);
	sec_btn->setGeometry(2 * M, M * 5 + BUTTON_HEIGHT, LINEWIDTH - 2 * M, BUTTON_HEIGHT);
	sec_btn->setText("I would improve my computer's security");


	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
	continue_btn->setEnabled(false);

	connect(this->perf_btn, &QRadioButton::clicked, this, &ImproveChoicePage::checkContinue);
	connect(this->sec_btn, &QRadioButton::clicked, this, &ImproveChoicePage::checkContinue);
}

ImproveChoicePage::~ImproveChoicePage()
{
}

QRadioButton* DecreaseChoicePage::perf_btn;
QRadioButton* DecreaseChoicePage::sec_btn;

void DecreaseChoicePage::checkContinue() {
	if (perf_btn->isChecked() || sec_btn->isChecked()) {
		continue_btn->setEnabled(true);
	}
	else {
		continue_btn->setEnabled(false);
	}
}

DecreaseChoicePage::DecreaseChoicePage(QWidget* parent)
	: QWidget(parent)
{

	label = new QLabel(this);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignJustify);
	label->setGeometry(M, 2 * M, LINEWIDTH, 4 * M);
	label->setText("If you had to choose between lowering your computer's performance or lowering your computer's security, which would you choose?");


	perf_btn = new QRadioButton(this);
	perf_btn->setGeometry(2 * M, M * 4, LINEWIDTH - 2 * M, BUTTON_HEIGHT);
	perf_btn->setText("I would lower my computer's performance");

	sec_btn = new QRadioButton(this);
	sec_btn->setGeometry(2 * M, M * 5 + BUTTON_HEIGHT, LINEWIDTH - 2 * M, BUTTON_HEIGHT);
	sec_btn->setText("I would lower my computer's security");


	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
	continue_btn->setEnabled(false);

	connect(this->perf_btn, &QRadioButton::clicked, this, &DecreaseChoicePage::checkContinue);
	connect(this->sec_btn, &QRadioButton::clicked, this, &DecreaseChoicePage::checkContinue);
}

DecreaseChoicePage::~DecreaseChoicePage()
{
}

