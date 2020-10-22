#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Globals.h"

class StartPage : public QWidget
{
	Q_OBJECT

public:
	StartPage(QWidget *parent = Q_NULLPTR);
	~StartPage();

	QLabel* label;
	QPushButton* consent_btn;
	QPushButton* not_consent_btn;
};

class ModPage : public StartPage
{
	Q_OBJECT

public:
	ModPage(QWidget* parent = Q_NULLPTR) : StartPage(parent) {
		label->setText("As part of this experiment, we will make temporary modifications to your computer. It is very important that your computer does not power down during this experiment. If you are using a battery-powered device such as a laptop, we recommend that you plug your device into a power source. If your computer powers down during this experiment, you will need to re-do this experiment to restore your computer to its original state and may also jeopardize your ability to earn money from participating in this experiment.\n\nAdditionally, please make sure your device is connected to the internet for the duration of the experiment.");

		consent_btn->setText("I consent and\nunderstand");
		consent_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH - M, M * 8, BUTTON_WIDTH, 2*BUTTON_HEIGHT));
		
		not_consent_btn->setText("Do not make changes\n to my computer");
		not_consent_btn->setGeometry(QRect(W / 2 + M, M * 8, BUTTON_WIDTH, 2*BUTTON_HEIGHT));

	}
};
