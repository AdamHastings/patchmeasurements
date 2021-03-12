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
		label->setText("We are now done with the task exercises. We will now ask a few questions based on your experience during the tasks.");
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
		QString text = "Thank you for your participation in this experiment. If we received three emails from you demonstrating that you completed the three tasks, we will respond to your email with a Prolific Completion Code. If you would like us to send the Completion Code to a different email address, please contact us at\nhastings-experiment@cs.columbia.edu.\n\nYou may now exit this window and delete this program from your computer.\n\n";

		if (REBOOT_AT_END) {
			text += "\n\nTo completely undo all changes made during this experiment, please reboot your computer now.";
		}

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


class Failed2UploadPage : public SingleChoicePage
{
	Q_OBJECT

public:
	Failed2UploadPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {
		label->setText("This program had trouble uploading your survey responses. In order for you to receive compnensation, we will need you to manually email the survey results to the researchers. To manually send the results, look for a file called \"results.txt\" in the same folder where you first ran this program. Attach this document to an email titled \"Results\" and send it to hastings-experiment@cs.columbia.edu.\n\nPlease send this email before continuing. If we do not receive this email, we cannot send you your compensation. We apologize for the inconvenience.");

	}
};