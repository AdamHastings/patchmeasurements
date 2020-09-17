#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>

class RankPage : public QWidget
{
	Q_OBJECT

public:
	RankPage(QWidget *parent = Q_NULLPTR);
	~RankPage();

	QListWidget* listWidget;
	QPushButton* continue_btn;


private:
	void enableContinue();
};
