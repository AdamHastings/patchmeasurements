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

	static QSpinBox* spin;
	QPushButton* continue_btn;

private:
	QLabel* label;
	void enableContinue();
};


// Curiously Redundant Design Pattern doesn't work here, because of some issue with the Qt Compiler
// So I'm not able to do OOP as intended and instead am repeating a lot of code unfortunately
// This is mostly because I need page objects to be static so that I can grab their values later
// And they need to be static for the static SysUtils::takeSnapshot method to work
// CRDP would solve this problem beautifully but simply doesn't work with the tools I have
// So my sincere apologies to myself and anyone else reading this
// Because I'm just going to be duplicating whole blocks of code from here on out :(

class DaysPage : public QWidget
{
	Q_OBJECT

public:
	DaysPage(QWidget* parent = Q_NULLPTR);

	static QSpinBox* spin;
	QPushButton* continue_btn;

private:
	QLabel* label;
	void enableContinue();
};