#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include "Globals.h"

class ImproveChoicePage : public QWidget
{
	Q_OBJECT

public:
	ImproveChoicePage(QWidget *parent = Q_NULLPTR);
	~ImproveChoicePage();

	QPushButton* continue_btn;
	QLabel* label;
	static QRadioButton* perf_btn;
	static QRadioButton* sec_btn;

private:
	void checkContinue();
};

class DecreaseChoicePage : public QWidget
{
	Q_OBJECT

public:
	DecreaseChoicePage(QWidget* parent = Q_NULLPTR);
	~DecreaseChoicePage();

	QPushButton* continue_btn;
	QLabel* label;
	static QRadioButton* perf_btn;
	static QRadioButton* sec_btn;

private:
	void checkContinue();
};


class PurchasePage : public QWidget
{
	Q_OBJECT

public:
	PurchasePage(QWidget* parent = Q_NULLPTR);

	QPushButton* continue_btn;
	QLabel* label;
	static QRadioButton* yes;
	static QRadioButton* no;

private:
	void checkContinue();
};

class ChoicePage : public QWidget
{
	Q_OBJECT

public:
	
	QPushButton* continue_btn;
	QLabel* label;
	static QRadioButton* choiceA;
	static QRadioButton* choiceB;

	ChoicePage(QWidget* parent = Q_NULLPTR);

protected:
	virtual void checkContinue();
};

class MoreDaysPage : public ChoicePage
{
	Q_OBJECT

public:
	MoreDaysPage(QWidget* parent = Q_NULLPTR);
};

//class InfiniteDaysPage : public ChoicePage
//{
//public:
//	InfiniteDaysPage(QWidget* parent = Q_NULLPTR);
//};

class SingleChoicePage : public QWidget
{
	Q_OBJECT

public:

	QPushButton* continue_btn;
	QLabel* label;
	QCheckBox* choice;

	SingleChoicePage(QWidget* parent = Q_NULLPTR);

protected:
	virtual void checkContinue();
	//virtual bool getChoice();

};

class UploadFailPage : public SingleChoicePage
{
public:
	UploadFailPage(QWidget* parent = Q_NULLPTR);
};