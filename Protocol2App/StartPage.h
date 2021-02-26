#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include "Globals.h"


class StartPage : public QWidget
{
	Q_OBJECT

public:
	StartPage(QWidget *parent = Q_NULLPTR);
	~StartPage();

	QLabel* label;
	QRadioButton* consent_btn;
	QRadioButton* not_consent_btn;
	QPushButton* continue_btn;

private:
	void checkIfContinue();
};

class ModPage : public StartPage
{
	Q_OBJECT

public:
	ModPage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		/*label->setText("As part of this experiment, we will make temporary modifications to you computer. It is very important that your computer does not power down during this experiment. If you are using a battery-powered device such as a laptop, we recommend that you plug your device into a power source. If your computer powers down during this experiment, you will need to re-do this experiment to restore your computer to its original state and may also jeopardize your ability to earn money from participating in this experiment.");*/
		label->setText("This experiment requires that this app make a temporary modification to your computer. Specifically, this modification changes the \"CsEnabled\" Windows registry key from a 1 to a 0, which gives your computer the ability to change it's running speed. This modification will persist for the duration of the experiment and will be undone once this experiment concludes. Do you allow this program to make this temporary change to your computer?");

		consent_btn->setText("I understand and consent");
		//consent_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH - M, M * 8, BUTTON_WIDTH, 2 * BUTTON_HEIGHT));

		not_consent_btn->setText("Do not make changes to my computer");
		//not_consent_btn->setGeometry(QRect(W / 2 + M, M * 8, BUTTON_WIDTH, 2 * BUTTON_HEIGHT));

	}

};




class HoursMonitorPage : public StartPage
{
	Q_OBJECT
public:
	HoursMonitorPage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		label->setText("In a moment, you will be asked to choose between money and computer performance. If you choose to accept the money, your device will be slowed down for 24 hours. If you accept the money, this program may monitor your device's speed to ensure that the slowdown has taken effect. Likewise, if you accept the money, this program may also log the number of hours you use the device to ensure that you are actually using your device while it is slowed down. This program will not track or log any other data about you while you use this device.\n\nDo you consent to having this program monitor your device's speed and hours active for the duration of the experiment?");
	}
};


class HoursMinimumPage : public StartPage
{
	Q_OBJECT
public:
	HoursMinimumPage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		label->setText("Based on your previous response, you reported to use this device " + QString::number(hours) + " per week on average. If you accept the money, you will be expected to use your device at least 0.75 x " + QString::number(hours) + " = " + QString::number(0.75 * hours) + " hours per week. If you do not use your device this many hours, we will consider you to be \"cheating\" the experiment and you will not be awarded compensation.\n\nDo you agree to use your device for at least " + QString::number(0.75 * hours) + " per week for the duration of this experiment, and do you understand the consequences if you do not?");
		consent_btn->setText("I agree and understand");
		not_consent_btn->setText("I do not agree");
	}

	void setHours(int input) {
		hours = input;
	}
private:
	int hours;
};


class PrimaryDevicePage : public StartPage
{
	Q_OBJECT
public:
	PrimaryDevicePage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		label->setText("This experiment requires that the device you are currently using is your primary computer. A \"primary computer\" is a computer that you use more than any other computer. For the purposes of this experiment, do not consider your phone as a primary computer.\n\nIs the computer you are currently using right now your primary computer?");
		consent_btn->setText("Yes");
		not_consent_btn->setText("No");
	}
};
