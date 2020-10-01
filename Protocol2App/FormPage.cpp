#include "FormPage.h"
#include "Globals.h"
#include "RegistryUtils.h"
#include "DropBox.h"
#include <algorithm>


void FormPage::uploadForm() {

	DropBox::setDirectory(QString::fromStdString(uni_str));


	std::string s = "";

	s += "name," + name_str + "\n";
	s += "UNI," + uni_str + "\n";
	s += "address," + address_str + "\n";
	s += "city," + city_str + "\n";
	s += "state," + state_str + "\n";
	s += "zip," + zip_str + "\n";

	DropBox::upload(QString::fromStdString(s), "PII");
}


void FormPage::updateRegistry() {

	name_str = line_name->text().toStdString();
	uni_str = line_uni->text().toStdString();
	address_str = line_address->text().toStdString();
	city_str = line_city->text().toStdString();
	state_str = line_state->text().toStdString();
	zip_str = line_zip->text().toStdString();

	std::replace(name_str.begin(), name_str.end(), ',', ' ');
	std::replace(uni_str.begin(), uni_str.end(), ',', ' ');
	std::replace(address_str.begin(), address_str.end(), ',', ' ');
	std::replace(city_str.begin(), city_str.end(), ',', ' ');
	std::replace(state_str.begin(), state_str.end(), ',', ' ');
	std::replace(zip_str.begin(), zip_str.end(), ',', ' ');

	RegistryUtils::setRegKey("name", line_name->text());
	RegistryUtils::setRegKey("UNI", line_uni->text());
	RegistryUtils::setRegKey("address", line_address->text());
	RegistryUtils::setRegKey("city", line_city->text());
	RegistryUtils::setRegKey("state", line_state->text());
	RegistryUtils::setRegKey("zip", line_zip->text());
}

void FormPage::submitForm() {
	updateRegistry();
	uploadForm();
}


void FormPage::updateContinueBtn(const QString& text) {
	if (
		line_name->text() != "" &&
		line_uni->text() != "" &&
		line_address->text() != "" &&
		line_city->text() != "" &&
		line_state->text() != "" &&
		line_zip->text() != ""
		) {
		
		continue_btn->setEnabled(true);
	}
}

void FormPage::makeConnections() {
	connect(this->line_name, &QLineEdit::textEdited, this, &FormPage::updateContinueBtn);
	connect(this->line_uni, &QLineEdit::textEdited, this, &FormPage::updateContinueBtn);
	connect(this->line_address, &QLineEdit::textEdited, this, &FormPage::updateContinueBtn);
	connect(this->line_city, &QLineEdit::textEdited, this, &FormPage::updateContinueBtn);
	connect(this->line_state, &QLineEdit::textEdited, this, &FormPage::updateContinueBtn);
	connect(this->line_zip, &QLineEdit::textEdited, this,
		&FormPage::updateContinueBtn);

	connect(this->continue_btn, &QPushButton::clicked, this, &FormPage::submitForm);
}

FormPage::FormPage(QWidget* parent)
	: QWidget(parent)
{

	// setup page layout
	header = new QLabel(this);
	header->setGeometry(QRect(M, M, LINEWIDTH, 2 * M));
	header->setWordWrap(true);
	header->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
	header->setText("Thank you for participating in this study. After this experiment concludes, we will mail you a Visa gift card worth the amount of money you'ved earned. To receive compensation, we will need your name and mailing address so that we can mail you this gift card.");

	name = new QLabel(this);
	name->setGeometry(2 * M, 3 * M, 2 * M, BUTTON_HEIGHT);
	name->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	name->setText("Name  ");
	line_name = new QLineEdit(this);
	line_name->setGeometry(4 * M, 3 * M, 4 * M, BUTTON_HEIGHT);

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
#if QT_NO_DEBUG
	continue_btn->setEnabled(false);
#endif

#ifdef QT_DEBUG
	line_name->setText("Adam Hastings");
	line_uni->setText("akh2167");
	line_address->setText("549 Riverside Dr. #4A");
	line_city->setText("New York");
	line_state->setText("NY");
	line_zip->setText("10027");
#endif

	makeConnections();
}

FormPage::~FormPage()
{
}
