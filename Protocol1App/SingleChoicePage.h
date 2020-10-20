#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QDebug>
#include "Globals.h"

class SingleChoicePage : public QWidget
{
	Q_OBJECT

public:
	SingleChoicePage(QWidget* parent = Q_NULLPTR);
	~SingleChoicePage();

	QPushButton* continue_btn;
	QLabel* label;

private:
};

class PreWTAPage : public SingleChoicePage
{
	Q_OBJECT

public:
	PreWTAPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {
	}

	void setLabelText(int throttled, int full_throttle, int slowdown) {
		QString text = "In the previous tasks, your computer ran at normal speeds during <b>Task 1</b> and <b>Task " + QString::number(full_throttle) + "</b>. ";
		text.append("During <b>Task " + QString::number(throttled) + "</b>, your computer's speed was reduced by <b>" + QString::number(slowdown) + "%</b>. ");
		text.append("\n\nIn the next section, you will be asked a series of questions designed to elicit how much you value the computer performance lost during <b>Task " + QString::number(throttled) + "</b>.");
		//// TODO are we pegging or limiting speed?
		label->setTextFormat(Qt::RichText);
		label->setText(text);
	}
};

class PostTasksPage : public SingleChoicePage
{
	Q_OBJECT

public:
	PostTasksPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {
		label->setText("We are now done with the task exercises. We will now ask a few questions based on your experience during the tasks.\n\nAt this point, you may also delete the previously created Google Docs if you wish.");
	}
};

class FinalPage : public SingleChoicePage
{
	Q_OBJECT

public:
	FinalPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {

		continue_btn->setVisible(false);
	}

	void updateText() {
		QString text = "Thank you for your participation in this experiment. If we received three emails from you demonstrating that you completed the three tasks, we will send a Visa gift card worth $15 to the provided mailing address within the next few days.\n\nYou may now exit this window and delete this app from your computer.";

		if (REBOOT_AT_END) {
			qDebug() << "adding text at end";
			text += "\n\nTo completely undo all changes made during this experiment, please reboot your computer now.";
		}
		qDebug() << "done adding text if at all";
		qDebug() << REBOOT_AT_END;

		label->setGeometry(2 * M, M, LINEWIDTH - 2 * M, M * 8);
		label->setText(text);
	}
};

class NoAdminPage : public SingleChoicePage
{
	Q_OBJECT

public:
	NoAdminPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {
		label->setText("This program is not running in Administrator mode. In order to conduct this experiment, you will need to allow this program to have Administrator privileges. Please exit this program and re-run it as Administrator (right click on program and click \"Run as Administrator\").");

		continue_btn->setVisible(false);
	}
};

/*
class DebriefPage : public SingleChoicePage
{
	Q_OBJECT

public:
	DebriefPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {
		label->setText("As previously stated, this computer was slowed down by 30% during <Task 2 or Task 3, depending on coin toss result>. You were not informed of this because part of what this experiment aimed to discover was whether or not this slowdown is perceptible to computer users. The reason for this deception was so that you would not pay extra attention to your device's performance; this was important to the integrity of this experiment because it mimics how computer hardware companies currently fix security issues in their products. Namely, computer hardware companies have recently been issuing fixes to security problems by issuing updates to their customers which can degrade performance by up to 30% in some reported cases. This experiment was designed to find out if such a slowdown makes a noticeable difference to everyday computer users.\n\nIn addition, this experiment was designed to elicit how much you value this amount of performance in terms of US dollars.\n\nIf you have additional questions about this deception, you may contact the researchers at hastings - experiment@cs.columbia.edu or the Human Resource Protection Office at  212 - 305 - 5883 or askirb@columbia.eduBecause this experiment involved deception, you have the right as a research participant to withdraw from the study.You will not be compensated if you withdraw from this experiment.Do you wish to withdraw ? ");
	}
};
*/