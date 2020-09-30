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
		label->setText("Your computer will remain slowed down for another 24 hours. After 24 hours have elapsed, you will again be given the choice to either restore your computer's performance or keep your computer slow in exchange for money.\n\n\nYou may now exit this window.");
	}
};

class NoMoreDaysPage : public ExitPage
{
	Q_OBJECT

public:
	NoMoreDaysPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Your computer's performance has been restored. This program will remove itself from your active processes and will no longer ask you daily questions.\n\nDuring this experiment, you endured x days of a slowed-down computer and have earned $y. You should expect to receive an Amazon gift card in your email inbox within the next few days. Thank you for your participation!\n\nYou may now exit this window. Afterwards, please delete this program from your computer.");
	}
};

class NoAdminPage : public ExitPage
{
	Q_OBJECT

public:
	NoAdminPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("This program is not running in Administrator mode. In order to conduct this experiment, you will need to allow this program to have Administrator privileges. Please exit this program and re-run it as Administrator (right click on program and click \"Run as Administrator\").");
	}
};

class GoodbyePage : public ExitPage
{
	Q_OBJECT

public:
	GoodbyePage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Thank you for your interest in this experiment. Unfortunately, you are not eligible to participate. You may now exit this window. You may also delete this program from your computer.\n\nIf you ended up on this page by mistake but still want to participate in this experiment, you can simply just re-run this application.");
	}
};
