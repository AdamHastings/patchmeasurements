#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <string>

class FormPage : public QWidget
{
	Q_OBJECT

public:
	FormPage(QWidget* parent = Q_NULLPTR);
	~FormPage();

	std::string name_str;
	std::string uni_str;
	/*
	std::string address_str;
	std::string city_str;
	std::string state_str;
	std::string zip_str;
	*/

	QPushButton* continue_btn;

private:

	QLabel* header;

	QLabel* name;
	QLabel* uni;
	/*
	QLabel* address;
	QLabel* city;
	QLabel* state;
	QLabel* zip;
	*/

	QLineEdit* line_name;
	QLineEdit* line_uni;
	/*
	QLineEdit* line_address;
	QLineEdit* line_city;
	QLineEdit* line_state;
	QLineEdit* line_zip;
	*/

private:
	void updateContinueBtn(const QString& text);
	void makeConnections();
	void updateRegistry();
	void uploadForm();
	void submitForm();
};
