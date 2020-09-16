#pragma once
#include "Globals.h"
#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLabel>
#include <QGroupBox>
#include "ButtonArray.h"

//class ButtonArray : public QButtonGroup
//{
//	Q_OBJECT
//
//public:
//	QRadioButton* muchslower;
//	QRadioButton* moderatelyslower;
//	QRadioButton* slightlyslower;
//	QRadioButton* aboutthesame;
//	QRadioButton* slightlyfaster;
//	QRadioButton* moderatelyfaster;
//	QRadioButton* muchfaster;
//
//	ButtonArray(QObject *parent = (QObject*)nullptr) {
//		muchslower = new QRadioButton(parent);
//		moderatelyslower = new QRadioButton(parent);
//		slightlyslower = new QRadioButton(parent);
//		aboutthesame = new QRadioButton(parent);
//		slightlyfaster = new QRadioButton(parent);
//		moderatelyfaster = new QRadioButton(parent);
//		muchfaster = new QRadioButton(parent);
//	}
//};

class ComparePage : public QWidget
{
	Q_OBJECT

public:
	ComparePage(QWidget *parent = Q_NULLPTR);
	~ComparePage();

	QLabel* header;
	QPushButton* continue_btn;
	ButtonArray* arr1;
	ButtonArray* arr2;
	ButtonArray* arr3;

private:
};
