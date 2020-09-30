#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Globals.h"

class DoubleCheck : public QWidget
{
	Q_OBJECT

public:
	DoubleCheck(QWidget *parent = Q_NULLPTR);
	~DoubleCheck();

	QLabel* label;
	QLabel* done_label;
	QPushButton* confirm_btn;
	QPushButton* mistake_btn;

protected:
	QString getTimestamp();
};

class DoubleCheckAccept : public DoubleCheck
{
	Q_OBJECT

public:
	DoubleCheckAccept(QWidget* parent = Q_NULLPTR);

private:
	void uploadChoice();
};

class DoubleCheckDecline : public DoubleCheck
{
	Q_OBJECT

public:
	DoubleCheckDecline(QWidget* parent = Q_NULLPTR);

private:
	void restoreDefaults();
	void uploadChoice();

	//void makeChoice() {
	//	DoubleCheck::makeChoice();
	//	done_label->setText("Done! Your computer's speed has been restored. ");
	//}
};
