#pragma once

#include <QWidget>
#include <QLabel>
#include "Globals.h"
#include <QDebug>
#include "RegistryUtils.h"
#include "SysUtils.h"
#include <QPushButton>

typedef enum retry_reason_t {
	NO_UPLOAD,
	NO_SLOWDOWN,
	INCOMPATIBLE
};

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

	void resetPage(int days, QString uni) {
		QString lastchr = uni[uni.length() - 1];
		//QString cc = COMPLETION_CODE + lastchr;
		QByteArray ba;
		ba.append("o" + uni);
		QString cc = ba.toBase64();
		//cc.remove(0, cc.length() - 6).toUpper();
		cc.chop(cc.length() - 8);

		QString labeltext;
		if (days == TOTAL_DAYS) {
			labeltext = "Your computer has been slowed down. You may now redeem your baseline compensation of $" + QString::number(BASELINE) + " by submitting the following completion for the HIT:\n\n" + cc + "\n\nAdditional earnings will later be paid via bonus payments in Mechanical Turk.\n\n";
		}
		else {
			labeltext = "Your computer will remain slowed down for another 24 hours. ";
		}

		labeltext += "When you close this computer program, the window will disappear but the program will not be killed: This program will sit idly in the background and will occasionally monitor your device's speed to ensure that it remains slowed down.\n\nIf you reboot your computer, this program will automatically restart itself (although you will have to re-authorize it to run as Administrator). After 24 hours have elapsed, this program will wake itself up and you will be given the choice to either restore your computer's performance or keep your computer slow in exchange for money.\n\n\nYou may now exit this window.";
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

	void resetPage(int days, int acceptances, QString uni) {
		QString lastchr = uni[uni.length() - 1];
		//QString cc = COMPLETION_CODE + lastchr;
		QByteArray ba;
		ba.append("n" + uni);
		QString cc = ba.toBase64();
		//cc.remove(0, cc.length() - 6).toUpper();
		cc.chop(cc.length() - 8);


		QString text;
		if (days == TOTAL_DAYS) {
			text = "Thank you for your participation! You have earned a baseline participation compensation of $" + QString::number(BASELINE) + " but will not earn any additional compensation. You may redeem this compensation via the following Mechanical Turk Completion Code:\n\n" + cc + "\n\nYou may now exit this window. Afterwards, please delete this program from your computer by running the \"uninstall\" program.";
		}
		else {
			text = "Thank you for your participation! Your computer's performance has been restored. During this experiment, you accepted slowing down your computer " + QString::number(acceptances) + " time(s), earning you $" + QString::number(OFFER) + " x " + QString::number(acceptances) + " = $" + QString::number(OFFER * acceptances) + ". Including your baseline participation compensation of $" + QString::number(BASELINE) + ", this brings your total earnings to $" + QString::number((OFFER * acceptances) + BASELINE) + ". You have already received the completion code for the baseline compensation. The remaining compensation will be paid to you as a bonus payment via Mechanical Turk.\n\nYou may now exit this window. Afterwards, please delete this program from your computer by running the \"uninstall\" program.";
		}
		if (SysUtils::REBOOT_AT_END) {
			text += " After you uninstall the program, please reboot your computer for all changes to be undone.";
		}
		label->setText(text);
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
		
	}

	void resetPage() {
		QString text = "Thank you for your interest in this experiment. Unfortunately, you are not eligible to participate.\n\nYou may now exit this window. Afterwards, please delete this program from your computer by running the \"uninstall\" program. Any changes made to your device have been undone.";

		if (SysUtils::REBOOT_AT_END) {
			text += " Please also reboot your device for all changes to be undone.";
		}
		label->setText(text);
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
		continue_btn = new QPushButton(this);
		continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
		continue_btn->setText("Retry");
	}

	void resetPage(retry_reason_t reason) {
		if (reason == NO_UPLOAD) {
			label->setText("The results failed to send correctly. This is likely because you are not connected to the internet. Please make sure you are connected to the internet and click the button below to try again.");
		}
		else if (reason == NO_SLOWDOWN) {
			label->setText("We had trouble slowing down your computer. Click the button below to try again.");
		}
		else {
			label->setText("This program ran into an unspecified problem. Please click the button below to try again.");
		}
	}
};

class CompNotEligiblePage : public ExitPage
{
	Q_OBJECT

public:
	CompNotEligiblePage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
	}

	void resetPage(QString uni, retry_reason_t reason) {
		QString lastchr = uni[uni.length() - 1];
		//QString cc = COMPLETION_CODE + lastchr;
		QByteArray ba;
		ba.append(uni);
		QString cc = ba.toBase64();
		//cc.remove(0, cc.length() - 6).toUpper();
		cc.chop(cc.length() - 8);

		if (reason == NO_UPLOAD) {
			label->setText("We are sorry, but we were unable to upload your results. We will award you the baseline compensation for your participation thus far, but unfortunately your computer is not compatible with running the rest of the experiment. Any temporary changes made to your computer have been undone.\n\nTo reedem the baseline compensation, please enter the following completion code into the HIT on Mechanical Turk:\n\n" + cc + "\n\nAfterwards, please delete this program from your computer by running the \"uninstall\" program.");
		}
		else if (reason == NO_SLOWDOWN) {
			label->setText("We are sorry, but we were unable to change your computer's speed. We will award you the baseline compensation for your participation thus far, but unfortunately your computer is not compatible with running the rest of the experiment. Any temporary changes made to your computer have been undone.\n\nTo reedem the baseline compensation, please enter the following completion code into the HIT on Mechanical Turk:\n\n" + cc + "\n\nAfterwards, please delete this program from your computer by running the \"uninstall\" program.");
		}
		else if (reason == INCOMPATIBLE) {
			label->setText("We are sorry, but your computer is incompatible with this experiment, and cannot participate in this study. No changes to your device have been made. This may be because you are not running this program in Windows 10 on a desktop or laptop device, or because you are running this program in a virtual machine. Please delete this program from your computer by running the \"uninstall\" program.");
		}
		else {
			label->setText("We are sorry, but your computer is incompatible with this experiment. We will award you the baseline compensation for your participation thus far, but unfortunately your computer is not compatible with running the rest of the experiment. Any temporary changes made to your computer have been undone.\n\nTo reedem the baseline compensation, please enter the following completion code into the HIT on Mechanical Turk:\n\n" + cc + "\n\nAfterwards, please delete this program from your computer by running the \"uninstall\" program.");
		}
		
	}
};

class WaitPage : public ExitPage
{
	Q_OBJECT

public:
	QPushButton* continue_btn;

	WaitPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
		label->setText("Press Continue to send your survey responses to the researchers.");

		continue_btn = new QPushButton(this);
		continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
		continue_btn->setText("Continue");
		continue_btn->setEnabled(false);
	}
};

//class TestEligibilityPage : public ExitPage
//{
//	Q_OBJECT
//
//public:
//	QPushButton* continue_btn;
//
//	TestEligibilityPage(QWidget* parent = Q_NULLPTR) : ExitPage(parent) {
//		label->setText("Press wait while we determine if your device is eligible to participate in this study. This may take up to a minute.");
//
//	}
//};