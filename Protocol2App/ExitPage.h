#pragma once

#include <QWidget>
#include <QLabel>
#include "Globals.h"
#include <QDebug>
#include "RegistryUtils.h"
#include "SysUtils.h"
#include <QPushButton>

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
	}

	void resetPage(int days) {
		QString labeltext;
		if (days == TOTAL_DAYS) {
			labeltext = "Your computer has been slowed down. You may now redeem your baseline compensation of " + QString::number(BASELINE) + " by entering the completion code " + COMPLETION_CODE + " into Mechanical Turk. Additional earnings will later be paid via bonus payments in Mechanical Turk.\n\n";
		}
		else {
			labeltext = "Your computer will remain slowed down for another 24 hours. ";
		}

		labeltext += "When you close this computer program, the window will disappear but the program will not be killed: This program will sit idly in the background and will occasionally monitor your device's speed to ensure that it remains slowed down.\n\nIf you reboot your computer, this program will automatically restart itself (although you may have to re-authorize it to run as Administrator). After 24 hours have elapsed, this program will wake itself up and you will be given the choice to either restore your computer's performance or keep your computer slow in exchange for money.\n\n\nYou may now exit this window.";
		label->setText(labeltext);
	}
};

class NoMoreDaysPage : public ExitPage
{
	Q_OBJECT

public:
	NoMoreDaysPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
	}

	void resetPage(int days, int acceptances) {
		if (days == TOTAL_DAYS) {
			label->setText("Thank you for your participation! You have earned a baseline participation compensation of $" + QString::number(BASELINE) + " but will not earn any additional compensation. You may redeem this compensation via the following Mechanical Turk Completion Code:\n\n" + COMPLETION_CODE + "\n\nYou may now exit this window. Afterwards, please delete this program from your computer by running the \"uninstall\" program. After you uninstall the program, please reboot your computer for all changes to take effect.");
		}
		else {
			label->setText("Thank you for your participation! Your computer's performance has been restored. During this experiment, you accepted slowing down your computer " + QString::number(acceptances) + " time(s), earning you $" + QString::number(OFFER) + " x " + QString::number(acceptances) + " = $" + QString::number(OFFER * acceptances) + ". Including your baseline participation compensation of $" + QString::number(BASELINE) + ", this brings your total earnings to $" + QString::number((OFFER * acceptances) + BASELINE) + ". You have already received the completion code for the baseline compensation. The remaining compensation will be paid to you as a bonus payment via Mechanical Turk.\n\nYou may now exit this window. Afterwards, please delete this program from your computer by running the \"uninstall\" program. After you uninstall the program, please reboot your computer for all changes to take effect.");
		}
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

class WrongInstallLocationPage : public ExitPage
{
	Q_OBJECT

public:
	WrongInstallLocationPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("This program has been installed at \n" + SysUtils::getpwd() + ", which is the wrong location. Please make sure that this program is located in \n C:\\Program Files\\" + RegistryUtils::AppName + "\\" + "Experiment.exe and try again.\n\nDid you remember to run the \"install\" program first?");
	}
};

class GoodbyePage : public ExitPage
{
	Q_OBJECT

public:
	GoodbyePage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Thank you for your interest in this experiment. Unfortunately, you are not eligible to participate.\n\nYou may now exit this window. Afterwards, please delete this program from your computer by running the \"uninstall\" program. Any changes made to your device have been undone. Please reboot your device for all undone changes to take effect.");
	}
};

class RestartPage : public ExitPage
{
	Q_OBJECT

public:
	RestartPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Your computer's configuration has been changed. You will need to reboot your computer for the changes to take place. Please restart your computer and re-run this program.");
	}
};

class TimeoutSplashPage : public ExitPage
{
	Q_OBJECT

public:
	QPushButton* continue_btn;

	TimeoutSplashPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Thank you for your participation in this experiment. You have participated in this experiment for the maximum of " + QString::number(TOTAL_DAYS) + " days. Your device's performance has been restored. To conclude this experiment, we will now ask you a few survey questions.");

		continue_btn = new QPushButton(this);
		continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
		continue_btn->setText("Continue");
	}
};

class RetryPage : public ExitPage
{
	Q_OBJECT

public:
	QPushButton* continue_btn;

	RetryPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("The results failed to send correctly. This is likely because you are not connected to the internet. Please make sure you are connected to the internet and click the button below to try again.");

		continue_btn = new QPushButton(this);
		continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
		continue_btn->setText("Retry");
	}
};

class CompNotEligiblePage : public ExitPage
{
	Q_OBJECT

public:
	CompNotEligiblePage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("We are sorry, but we were either unable to correctly change your computer's speed or unable to upload your results. We will award you the baseline compensation for your participation thus far, but unfortunately your computer is not compatible with running the rest of the experiment. Any temporary changes made to your computer have been undone.\n\nTo reedem the baseline compensation, please enter the following completion code into the HIT on Mechanical Turk:\n\n" + COMPLETION_CODE);
	}
};