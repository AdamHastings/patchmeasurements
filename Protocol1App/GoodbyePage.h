#pragma once

#include <QWidget>
#include <QLabel>
#include "Globals.h"

class GoodbyePage : public QWidget
{
	Q_OBJECT

public:
	GoodbyePage(QWidget *parent = Q_NULLPTR);
	~GoodbyePage();

protected:
	QLabel* label;
};

class ModMadePage : public GoodbyePage
{
	Q_OBJECT

public:
	ModMadePage(QWidget* parent = Q_NULLPTR) : GoodbyePage(parent) {
		label->setText("Your computer's configuration has been changed. You will need to reboot your computer for the changes to take place. Please restart your computer and re-run this program.");
	}
};

class NotEligiblePage : public GoodbyePage
{
	Q_OBJECT

public:
	NotEligiblePage(QWidget* parent = Q_NULLPTR) : GoodbyePage(parent) {

	}

	void updateText() {
		QString text = "Thank you for your interest in this experiment. Unfortunately, your device is not compatible with this program, and we can't consider you for participation. We apologize for any inconvenience. Any changes to your device have been undone.\n\n";

		if (REBOOT_AT_END) {
			text += "\n\nDid you reboot your computer when asked? This could be the reason why this program failed. If you didn't reboot your computer when prompted, re-run this program first and then reboot when prompted.";
		}
		label->setText(text);
	}
};

