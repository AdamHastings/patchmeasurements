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

	/*QLabel* name;
	QLabel* uni;
	QLabel* label;
	QLabel* address;
	QLabel* city;
	QLabel* state;
	QLabel* zip;

	QLineEdit* name;
	QLineEdit* uni;
	QLineEdit* label;
	QLineEdit* address;
	QLineEdit* city;
	QLineEdit* state;
	QLineEdit* zip;*/
};
