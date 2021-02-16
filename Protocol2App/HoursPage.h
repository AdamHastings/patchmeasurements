#pragma once

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

class HoursPage : public QWidget
{
	Q_OBJECT

public:
	HoursPage(QWidget* parent = Q_NULLPTR);
	~HoursPage();

	QSpinBox* spin;
	QPushButton* continue_btn;

private:
	QLabel* label;
	void enableContinue();
};
