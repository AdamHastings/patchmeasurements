#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>

class RankPage : public QWidget
{
	Q_OBJECT

public:
	RankPage(QWidget *parent = Q_NULLPTR);
	~RankPage();

	//QListWidget* listWidget;
	QPushButton* continue_btn;
	QRadioButton* task2_slower;
	QRadioButton* nodifference;
	QRadioButton* task3_slower;

};
