#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>

class WithdrawPage : public QWidget
{
	Q_OBJECT

public:
	WithdrawPage(QWidget *parent = Q_NULLPTR);
	~WithdrawPage();
	void Withdraw();

	/*QPushButton* withdraw_btn;
	QPushButton* dont_withdraw_btn;*/

	QRadioButton* withdraw_btn;
	QRadioButton* dont_withdraw_btn;
	QPushButton* continue_btn;

private:
	QLabel* label;
	QLabel* withdrawn;

};
