#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class WTAPage : public QWidget
{
	Q_OBJECT

public:
	WTAPage(QWidget *parent = Q_NULLPTR);
	~WTAPage();

	QLabel* header;
	QLabel* offer_label;
	QPushButton* yes_btn;
	QPushButton* no_btn;

	void updateOffer(int new_offer);

};
