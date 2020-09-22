#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Globals.h"

class DoubleCheck : public QWidget
{
	Q_OBJECT

public:
	DoubleCheck(QWidget *parent = Q_NULLPTR);
	~DoubleCheck();

	QLabel* label;
	QLabel* done_label;
	QPushButton* confirm_btn;
	QPushButton* mistake_btn;

	// void makeChoice();

private:
};

class DoubleCheckAccept : public DoubleCheck
{
	Q_OBJECT

public:
	DoubleCheckAccept(QWidget* parent = Q_NULLPTR) : DoubleCheck(parent) {
		label->setText("You've selected to continue slowing down your computer by " + QString::number(SLOWDOWN) + "% for another 24 hours in exchange for $" + QString::number(OFFER) + ".\nIs this choice correct?");
		// TODO "is this choice correct" sounds weird. But "Are you sure this is what you want to do?" may influence the psychology of the participants. Ask...
	}
};

class DoubleCheckDecline : public DoubleCheck
{
	Q_OBJECT

public:
	DoubleCheckDecline(QWidget* parent = Q_NULLPTR) : DoubleCheck(parent) {
		label->setText("You've selected to restore your computer to full performance. This selection means that you will be ineligible to earn any more money from this experiment. If you confirm your choice below, your computer will be restored to full performance, this app will close (you may also delete it from your computer), and you will no longer be asked daily to choose between computer performance and money. Is this choice correct?");
	}

	//void makeChoice() {
	//	DoubleCheck::makeChoice();
	//	done_label->setText("Done! Your computer's speed has been restored. ");
	//}
};
