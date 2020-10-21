#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class DebriefPage : public QWidget
{
	Q_OBJECT

public:
	DebriefPage(QWidget *parent = Q_NULLPTR);
	~DebriefPage();

public:
	QPushButton* yes_btn;
	QPushButton* no_btn;

	void setLabelText(int throttled, int slowdown);

private:
	QLabel* label;
	QLabel* confirm_label;

};
