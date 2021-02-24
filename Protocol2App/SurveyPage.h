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

	static QCheckBox* not_enough_money;
	static QCheckBox* mistrust;
	static QCheckBox* other_users;
	static QCheckBox* malfunction;
	static QCheckBox* other;

	static QDoubleSpinBox* wta_input;
	static QTextEdit* other_reason;
	static QTextEdit* malfunction_reason;

private:
	QLabel* label;
	QLabel* offerq;

	

	void setupPage();
	void makeConnections();
	void checkIfContinue();

	void not_enough_money_clicked();
	void other_users_clicked();
	void mistrust_clicked();
	void malfunction_clicked();
	void other_clicked();
};
