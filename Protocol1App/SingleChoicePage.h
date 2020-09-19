#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>

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
		label->setText("Thank you for your participation in this experiment. If we received three emails from you demonstrating that you completed the three tasks, you should expect to receive an email containing a link to an Amazon gift card in the next few days.\n\nYou may now exit this window.");

		continue_btn->setVisible(false);
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

