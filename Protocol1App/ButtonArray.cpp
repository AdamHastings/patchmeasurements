#include "ButtonArray.h"
#include "Globals.h"

ButtonArray::ButtonArray(QWidget *parent)
	: QGroupBox(parent)
{

	speed0 = new QRadioButton("About\nthe same");
	speed1 = new QRadioButton("Slightly\nfaster");
	speed2 = new QRadioButton("Moderately\nfaster");
	speed3 = new QRadioButton("Much faster\n(twice as fast)");
	speed4 = new QRadioButton("More than\ntwice as fast");

	hbox = new QHBoxLayout(this);
	hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	//bgroup = new QButtonGroup(this);

	hbox->insertWidget(0, speed0);
	hbox->insertWidget(1, speed1);
	hbox->insertWidget(2, speed2);
	hbox->insertWidget(3, speed3);
	hbox->insertWidget(4, speed4);
	//hbox->addWidget(bgroup);

	/*bgroup->addButton(speed0, 0);
	bgroup->addButton(speed1, 1);
	bgroup->addButton(speed2, 2);
	bgroup->addButton(speed3, 3);
	bgroup->addButton(speed4, 4);*/

	hbox->setSpacing(M);
	this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	this->setLayout(hbox);
}

ButtonArray::~ButtonArray()
{
}

int ButtonArray::getClicked() {
	if (speed0->isChecked()) {
		return 0;
	} else if (speed1->isChecked()) {
		return 1;
	} else if (speed2->isChecked()) {
		return 2;
	} else if (speed3->isChecked()) {
		return 3;
	} else if (speed4->isChecked()) {
		return 4;
	}
	else {
		return -1;
	}
}
