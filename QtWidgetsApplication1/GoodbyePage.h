#pragma once
#include <QWidget>
#include <QLabel>

class GoodbyePage : public QWidget
{
	Q_OBJECT

public:
	GoodbyePage(QWidget* parent = nullptr);
	~GoodbyePage();

private:
	QLabel *label;
};
