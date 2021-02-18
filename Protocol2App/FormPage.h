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

	QPushButton* continue_btn;

private:

	QLabel* header;

	QLabel* name;
	QLabel* uni;

	QLineEdit* line_name;
	QLineEdit* line_uni;

private:
	void updateContinueBtn(const QString& text);
	void makeConnections();
	void updateRegistry();
	void submitForm();
};
