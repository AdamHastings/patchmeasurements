#pragma once

#include <QWidget>
#include <QLabel>

class GoodbyePage : public QWidget
{
	Q_OBJECT

public:
	GoodbyePage(QWidget *parent = Q_NULLPTR);
	~GoodbyePage();

private:
	QLabel* label;
};
