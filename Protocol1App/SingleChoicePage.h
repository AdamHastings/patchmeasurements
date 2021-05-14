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

	void updateText(QString uni) {

		QString lastchr = uni[uni.length() - 1];
		QString cc = COMPLETION_CODE + lastchr;


		QString text = "Thank you for your participation in this experiment. Please enter the following Completion Code into the HIT submission box:\n\n" + cc + "\n\nIf we received the three uploaded files from you demonstrating that you completed the three tasks and the HIT submission box is correct, we will approve this HIT. You may now exit this window and delete this program from your computer.\n\n";

		if (REBOOT_AT_END) {
			text += "To completely undo all changes made during this experiment, please reboot your computer now.";
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
		label->setText("We are not able to successfully upload your survey responses. We will need you to manually email the survey results to the researchers. To manually send the results, look for a file called \"results.txt\" in the same folder where you first ran this program. Then upload this file to " + UPLOAD_WEBPAGE + "/upload.html before continuing. We apologize for the inconvenience.");

	}
};

class RetryUploadPage : public SingleChoicePage
{
	Q_OBJECT

public:
	RetryUploadPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {
		label->setText("This program had trouble uploading your survey responses. Please make sure you are connected to the internet. Click \"Continue\" below to try again.");

	}
};