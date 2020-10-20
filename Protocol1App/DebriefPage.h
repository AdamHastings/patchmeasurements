#pragma once

#include <QWidget>
#include <QLabel>

class DebriefPage : public QWidget
{
	Q_OBJECT

public:
	DebriefPage(QWidget *parent = Q_NULLPTR);
	~DebriefPage();

private:
	QLabel* label;
};
