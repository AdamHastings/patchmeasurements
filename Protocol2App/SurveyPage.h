#pragma once

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QTextEdit>

class SurveyPage : public QWidget
{
	Q_OBJECT

public:
	SurveyPage(QWidget *parent = Q_NULLPTR);
	~SurveyPage();

	QPushButton* continue_btn;
	

	//void firstOffer();
	void resetPage(int days);

private:
	QLabel* label;

	QCheckBox* not_enough_money;
	QCheckBox* mistrust;
	QCheckBox* other;

	QLabel* offerq;
	QDoubleSpinBox* wta_input;
	QTextEdit* other_reason;

	void setupPage();
	void makeConnections();
	void checkIfContinue();

	void not_enough_money_clicked();
	void mistrust_clicked();
	void other_clicked();
};
