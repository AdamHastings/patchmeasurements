#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>

class SingleChoicePage : public QWidget
{
	Q_OBJECT

public:
	SingleChoicePage(QWidget *parent = Q_NULLPTR);
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
		////QString text = "In the previous tasks, you computer was unmodified during <b>Task 1</b>."; //  +QString::number(1)
		//QString text = "In the previous tasks, your computer ran at normal speeds during <b>Task 1</b> and <b>Task " + QString::number(full_throttle) + "</b>.";
		////text.append("We made your computer run as fast as possible during <b>Task " + QString::number(full_throttle) + "</b>."
		//text.append("During <b>Task " + QString::number(throttled) + "</b>, your computer's speed was reduced by <b>" + QString::number(slowdown) + "%</b>.");
		//text.append("\n\nIn the next section, you will be asked a series of questions designed to elicit how much you value the computer performance lost during <b>Task " + QString::number(throttled) + "</b>.");
		////// TODO are we pegging or limiting speed?
		//label->setTextFormat(Qt::RichText);
		//label->setText(text);
	}

	void setLabelText(int throttled, int full_throttle, int slowdown) {
		QString text = "In the previous tasks, your computer ran at normal speeds during <b>Task 1</b> and <b>Task " + QString::number(full_throttle) + "</b>.";
		text.append("During <b>Task " + QString::number(throttled) + "</b>, your computer's speed was reduced by <b>" + QString::number(slowdown) + "%</b>.");
		text.append("\n\nIn the next section, you will be asked a series of questions designed to elicit how much you value the computer performance lost during <b>Task " + QString::number(throttled) + "</b>.");
		//// TODO are we pegging or limiting speed?
		label->setTextFormat(Qt::RichText);
		label->setText(text);
	}
};

//class PostTasksPage : public SingleChoicePage
//{
//	Q_OBJECT
//
//		PostTaksPage(QWidget* parent = Q_NULLPTR) : SingleChoicePage(parent) {
//		label->setText("We are now done with the task exercises. We will now ask a few questions based on your experience.");
//	}
//};


