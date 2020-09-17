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

	hbox = new QHBoxLayout();
	hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	hbox->insertWidget(0, speed0);
	hbox->insertWidget(1, speed1);
	hbox->insertWidget(2, speed2);
	hbox->insertWidget(3, speed3);
	hbox->insertWidget(4, speed4);

	hbox->setSpacing(M);
	this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	this->setLayout(hbox);

}

ButtonArray::~ButtonArray()
{
}
