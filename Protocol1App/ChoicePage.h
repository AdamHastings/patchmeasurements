#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>

class ImproveChoicePage : public QWidget
{
	Q_OBJECT

public:
	ImproveChoicePage(QWidget* parent = Q_NULLPTR);
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
