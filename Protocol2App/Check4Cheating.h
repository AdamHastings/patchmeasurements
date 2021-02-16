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
	static QRadioButton* cheated_btn;
	static QRadioButton* honest_btn;
	static QTextEdit* details;

	QPushButton* continue_btn;


private:
	QLabel* label;
	QLabel* ask_for_details;

private:
	void checkIfContinue();
};
