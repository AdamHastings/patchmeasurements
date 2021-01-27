#pragma once

#include <QWidget>
#include <QLabel>
#include "Globals.h"
#include <QDebug>
#include "RegistryUtils.h"
#include "SysUtils.h"

class ExitPage : public QWidget
{
	Q_OBJECT

public:
	ExitPage(QWidget *parent = Q_NULLPTR);
	~ExitPage();

	QLabel* label;

};

class EarningsPage : public ExitPage
{
	Q_OBJECT

public:
	EarningsPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
	}


};

class OneMoreDayPage : public ExitPage
{
	Q_OBJECT

public:
	OneMoreDayPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
		//label->setText("Your computer will remain slowed down for another 24 hours. After 24 hours have elapsed, you will again be given the choice to either restore your computer's performance or keep your computer slow in exchange for money.\n\n\nYou may now exit this window.");
	}

	void resetPage(int days) {
		if (days == TOTAL_DAYS) {
			label->setText("Your computer has been slowed down. After 24 hours have elapsed, you will again be given the choice to either restore your computer's performance or keep your computer slow in exchange for money.\n\n\nYou may now exit this window.");
		}
		else {
			label->setText("Your computer will remain slowed down for another 24 hours. After 24 hours have elapsed, you will again be given the choice to either restore your computer's performance or keep your computer slow in exchange for money.\n\n\nYou may now exit this window.");
		}
	}

	/*void firstOffer() {
		label->setText("Your computer has been slowed down. After 24 hours have elapsed, you will again be given the choice to either restore your computer's performance or keep your computer slow in exchange for money.\n\n\nYou may now exit this window.");
	}*/
};

class NoMoreDaysPage : public ExitPage
{
	Q_OBJECT

public:
	NoMoreDaysPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
		//label->setText("During this experiment, you endured x days of a slowed-down computer and have earned $y. You should expect to receive an Amazon gift card in your email inbox within the next few days. Thank you for your participation!\n\nYou may now exit this window. Afterwards, please delete this program from your computer.");
	}

	void resetPage(int days) {
		qDebug() << "nomoredays days: " << days;
		if (days == TOTAL_DAYS) {
			label->setText("Thank you for your participation! You have earned a participation fee of $5 but will not earn any additional compensation. You will receive this compensation via a prepaid debit card sent to your UNI's email.\n\nYou may now exit this window. Afterwards, please delete this program from your computer.");
		}
		else {
			label->setText("Thank you for your participation! Your computer's performance has been restored. During this experiment, you endured " + QString::number(TOTAL_DAYS - days) + " days of a slowed-down computer and have accrued " + QString::number(TOTAL_DAYS - days) + " x $" + QString::number(OFFER) + " = $" + QString::number(OFFER * (TOTAL_DAYS - days)) + ", in addition to a participation fee of $5. This brings your total earnings to $" + QString::number((OFFER * (TOTAL_DAYS - days)) + 5) + ". You will receive this compensation via a prepaid debit card sent to your UNI's email.\n\nYou may now exit this window. Afterwards, please delete this program from your computer.");
		}
	}

	/*void firstOffer() {
		label->setText("You have earned a participation fee of $5 but will not earn any additional compensation. In the next few days, we will mail you a Visa gift card to your provided address. Thank you for your participation!\n\nYou may now exit this window. Afterwards, please delete this program from your computer.");
	}*/
};

class NoAdminPage : public ExitPage
{
	Q_OBJECT

public:
	NoAdminPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("This program is not running in Administrator mode. In order to conduct this experiment, you will need to allow this program to have Administrator privileges. Please exit this program and re-run it as Administrator (right click on program and click \"Run as Administrator\").");
	}
};

class WrongInstallLocationPage : public ExitPage
{
	Q_OBJECT

public:
	WrongInstallLocationPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("This program has been installed at \n" + SysUtils::getpwd() + ", which is the wrong location. Please make sure that this program is located in \n C:\\Program Files\\" + RegistryUtils::AppName + "\\" + RegistryUtils::AppName + ".exe and try again.");
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