#include "ChoicePage.h"
#include "Globals.h"
#include <QDebug>


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

ImproveChoicePage::ImproveChoicePage(QWidget *parent)
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

ChoicePage::ChoicePage(QWidget* parent) {
	label = new QLabel(this);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignJustify);
	label->setGeometry(M, 2 * M, LINEWIDTH, 4 * M);

	choiceA = new QRadioButton(this);
	choiceA->setGeometry(2 * M, M * 4, LINEWIDTH - 2 * M, BUTTON_HEIGHT);

	choiceB = new QRadioButton(this);
	choiceB->setGeometry(2 * M, M * 5 + BUTTON_HEIGHT, LINEWIDTH - 2 * M, BUTTON_HEIGHT);

	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
	continue_btn->setEnabled(false);

	connect(this->choiceA, &QRadioButton::clicked, this, &ChoicePage::checkContinue);
	connect(this->choiceB, &QRadioButton::clicked, this, &ChoicePage::checkContinue);
}

void ChoicePage::checkContinue() {
	if (choiceA->isChecked() || choiceB->isChecked()) {
		continue_btn->setEnabled(true);
	}
	else {
		continue_btn->setEnabled(false);
	}
}

QRadioButton* MoreDaysPage::choiceA;
QRadioButton* MoreDaysPage::choiceB;


MoreDaysPage::MoreDaysPage(QWidget* parent) {
	qDebug() << "******OFFER: ";
	qDebug() << QString::number(OFFER);
	label->setText("If given the option, would you choose to keep your computer permanently slowed down by " + QString::number(SLOWDOWN) + "% in exchange for $" + QString::number(OFFER) + " per day?");
	choiceA->setText("Yes");
	choiceB->setText("No");
}

//QRadioButton* InfiniteDaysPage::choiceA;
//QRadioButton* InfiniteDaysPage::choiceB;
//
//
//InfiniteDaysPage::InfiniteDaysPage(QWidget* parent) {
//	label->setText("If given the option, would you make your computer permanently slower by " + QString::number(SLOWDOWN) + "% in exchange for $" + QString::number(OFFER) + " per day?");
//	choiceA->setText("Yes");
//	choiceB->setText("No");
//}


SingleChoicePage::SingleChoicePage(QWidget* parent) {
	label = new QLabel(this);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignJustify);
	label->setGeometry(M, 2 * M, LINEWIDTH, 4 * M);

	choice = new QCheckBox(this);
	choice->setGeometry(2 * M, M * 4, LINEWIDTH - 2 * M, BUTTON_HEIGHT);

	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
	continue_btn->setEnabled(false);

	connect(this->choice, &QCheckBox::clicked, this, &SingleChoicePage::checkContinue);
}

void SingleChoicePage::checkContinue() {
	if (choice->isChecked()) {
		continue_btn->setEnabled(true);
	}
	else {
		continue_btn->setEnabled(false);
	}
}

UploadFailPage::UploadFailPage(QWidget* parent) {
	label->setText("We had trouble uploading your results. We will need you to upload your survey results. To manually send the results, look for a file called \"results.txt\" on your Desktop. Then upload this file to\n" + UPLOAD_WEBPAGE + " before continuing. We apologize for the inconvenience.");

	choice->setText("I have successfully uploaded the file \"results.txt\" to the above website");
}


void PurchasePage::checkContinue() {
	if (yes->isChecked() || no->isChecked()) {
		continue_btn->setEnabled(true);
	}
	else {
		continue_btn->setEnabled(false);
	}
}



QRadioButton* PurchasePage::yes;
QRadioButton* PurchasePage::no;


PurchasePage::PurchasePage(QWidget* parent)
	: QWidget(parent)
{

	label = new QLabel(this);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignJustify);
	label->setGeometry(M, 2 * M, LINEWIDTH, 4 * M);
	label->setText("Did you purchase the computer used to run this program?");


	yes = new QRadioButton(this);
	yes->setGeometry(2 * M, M * 4, LINEWIDTH - 2 * M, BUTTON_HEIGHT);
	yes->setText("Yes");

	no = new QRadioButton(this);
	no->setGeometry(2 * M, M * 5 + BUTTON_HEIGHT, LINEWIDTH - 2 * M, BUTTON_HEIGHT);
	no->setText("No");


	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
	continue_btn->setEnabled(false);

	connect(this->yes, &QRadioButton::clicked, this, &PurchasePage::checkContinue);
	connect(this->no, &QRadioButton::clicked, this, &PurchasePage::checkContinue);
}
