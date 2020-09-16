#pragma once

#include <QWidget>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRect>

class ButtonArray : public QGroupBox
{
	Q_OBJECT

public:
	ButtonArray(QWidget *parent = Q_NULLPTR);
	~ButtonArray();

	QGroupBox* box;
	QVBoxLayout* vbox;
	QHBoxLayout* hbox;

	QRadioButton* muchslower;
	QRadioButton* moderatelyslower;
	QRadioButton* slightlyslower;
	QRadioButton* aboutthesame;
	QRadioButton* slightlyfaster;
	QRadioButton* moderatelyfaster;
	QRadioButton* muchfaster;
};
