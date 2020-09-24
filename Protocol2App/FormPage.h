#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "Globals.h"

class FormPage : public QWidget
{
	Q_OBJECT

public:
	FormPage(QWidget *parent = Q_NULLPTR);
	~FormPage();

	QLabel* label;
	QLineEdit* line;
	QPushButton* continue_btn;

private:
	void enableContinueBtn(const QString& text);

};
