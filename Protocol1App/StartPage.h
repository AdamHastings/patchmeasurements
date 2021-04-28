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
	StartPage(QWidget* parent = Q_NULLPTR);
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
		label->setText("This experiment requires that this app make a temporary modification to your computer for it to function correctly. This modification will persist for the duration of the experiment and will be undone once this experiment concludes. Do you allow this program to make this temporary change to your computer?");

		consent_btn->setText("I understand and consent");
		not_consent_btn->setText("Do not make changes to my computer");
	}
};




class MonitorPage : public StartPage
{
	Q_OBJECT
public:
	MonitorPage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		label->setText("This program may collect some details about your computer's hardware configuration, such as the the number of cores in your CPU and amount of RAM installed, but will not track or log any personal data about you.\n\nDo you consent to having this program monitor your computer's hardware configuration for the duration of the experiment?");
	}
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

class InternetPage : public StartPage
{
	Q_OBJECT
public:
	InternetPage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		label->setText("At the end of this experiment, you will be asked some survey questions. To ensure that the researchers receive your results, please make sure your computer is connected to the internet for the duration of this experiment. Likewise, if you are using a laptop, please make sure you are connected to power.\n\nDo you agree to keep your computer connected to power and to the internet for the duration of this experiment?");
		consent_btn->setText("I understand and agree");
		not_consent_btn->setText("No");
	}
};

class RegEditConsentPage : public StartPage
{
	Q_OBJECT
public:
	RegEditConsentPage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		label->setText("As part of this experiment, we will make some temporary modifications to your computer. However, your computer's current configuration does not allow us to make these modifications. We will need to make some temporary changes to your computer and then have you reboot your device. Please note that all modifications made to your computer are temporary and will be reversed at the end of this experiment. Do you allow us to make temporary, reversible changes to your computer?");
		consent_btn->setText("I understand and agree");
		not_consent_btn->setText("No");
	}
};
