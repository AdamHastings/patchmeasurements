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

class NotEligiblePage : public GoodbyePage
{
	Q_OBJECT

public:
	NotEligiblePage(QWidget* parent = Q_NULLPTR) : GoodbyePage(parent) {

	}

	void updateText() {
		label->setAlignment(Qt::AlignJustify);
		QString text = "Thank you for your interest in this experiment. Unfortunately, your device is not compatible with this program, and you are not eligible to participate in this experiment. We apologize for any inconvenience. Any changes to your device have been undone.\n\nIf you have any questions, comments, or concerns about this experiment or your participation, you may contact the researchers at hastings-experiment@cs.columbia.edu.";

		if (REBOOT_AT_END) {
			text += "\n\nTo completely undo all changes made during this experiment, please reboot your computer now.";
		}

		label->setText(text);
	}
};
