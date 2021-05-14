#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>

class RankPage : public QWidget
{
	Q_OBJECT

public:
	RankPage(QWidget *parent = Q_NULLPTR);
	~RankPage();

	//QListWidget* listWidget;
	QLabel* label;
	QPushButton* continue_btn;
	QRadioButton* task2_slower;
	QRadioButton* nodifference;
	QRadioButton* task3_slower;

};

class AttentionCheckPage : public RankPage
{
	Q_OBJECT
public:
	AttentionCheckPage(QWidget* parent = Q_NULLPTR); // : RankPage(parent);
};
