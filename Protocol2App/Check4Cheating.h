#pragma once

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QTextEdit>

class Check4Cheating : public QWidget
{
	Q_OBJECT

public:
	Check4Cheating(QWidget *parent = Q_NULLPTR);
	~Check4Cheating();

public:
	QRadioButton* cheated_btn;
	QRadioButton* honest_btn;
	QPushButton* continue_btn;
	QTextEdit* details;

private:
	QLabel* label;
	QLabel* ask_for_details;

private:
	void checkIfContinue();
};
