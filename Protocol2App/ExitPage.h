#pragma once

#include <QWidget>
#include <QLabel>

class ExitPage : public QWidget
{
	Q_OBJECT

public:
	ExitPage(QWidget *parent = Q_NULLPTR);
	~ExitPage();

	QLabel* label;

};

class OneMoreDayPage : public ExitPage
{
	Q_OBJECT

public:
	OneMoreDayPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Your computer will remain slowed down for another 24 hours. After 24 hours have elapsed, you will again be given the choice to either restore your computer's performance or continue slowing it down in exchange for money.\n\n\nYou may exit this window.");
	}
};

class NoMoreDaysPage : public ExitPage
{
	Q_OBJECT

public:
	NoMoreDaysPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Your computer's performance has been restored. This program will remove itself from your active processes and will no longer ask you daily questions.\n\nYou endured x days of a slowed-down computer and have earned $y. You should expect to receive an Amazon gift card in your email inbox within the next few days. Thank you for your participation!\n\n\nYou may now exit this window. Afterwards, please delete this program from your computer.");
	}
};
