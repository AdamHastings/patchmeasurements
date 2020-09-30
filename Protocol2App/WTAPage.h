#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>

class WTAPage : public QWidget
{
	Q_OBJECT

public:
	WTAPage(QWidget* parent = Q_NULLPTR);
	~WTAPage();

	QLabel* header;
	QLabel* offer_label;
	QPushButton* continue_btn;
	//QPushButton* no_btn;
	QRadioButton* accept;
	QRadioButton* decline;

	void updateOffer(int new_offer);

private:
	void uploadAnswers();

};
