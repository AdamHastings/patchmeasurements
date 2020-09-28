#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class FormPage : public QWidget
{
	Q_OBJECT

public:
	FormPage(QWidget *parent = Q_NULLPTR);
	~FormPage();


	QPushButton* continue_btn;

private:

	QLabel* header;

	QLabel* name;
	QLabel* uni;
	QLabel* address;
	QLabel* city;
	QLabel* state;
	QLabel* zip;

	QLineEdit* line_name;
	QLineEdit* line_uni;
	QLineEdit* line_address;
	QLineEdit* line_city;
	QLineEdit* line_state;
	QLineEdit* line_zip;
};
