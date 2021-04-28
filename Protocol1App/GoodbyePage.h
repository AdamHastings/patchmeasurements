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

//class NotEligiblePage : public GoodbyePage
//{
//	Q_OBJECT
//
//public:
//	NotEligiblePage(QWidget* parent = Q_NULLPTR) : GoodbyePage(parent) {
//
//	}
//
//	void updateText() {
//		QString text = "Thank you for your interest in this experiment. Unfortunately, your device is not compatible with this program, and you are not eligible to participate in this experiment. We apologize for any inconvenience. Any changes to your device have been undone.\n\nIf you have any questions, comments, or concerns about this experiment or your participation, you may contact the researchers at hastings-experiment@cs.columbia.edu.";
//
//		if (REBOOT_AT_END) {
//			text += "\n\nTo completely undo all changes made during this experiment, please reboot your computer now.";
//		}
//
//		label->setText(text);
//	}
//};

