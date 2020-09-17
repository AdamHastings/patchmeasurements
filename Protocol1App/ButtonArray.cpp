#include "ButtonArray.h"
#include "Globals.h"

ButtonArray::ButtonArray(QWidget *parent)
	: QGroupBox(parent)
{
	//box = new QGroupBox();

	/*muchslower = new QRadioButton("Much\nslower");
	moderatelyslower = new QRadioButton("Moderately\nslower");
	slightlyslower = new QRadioButton("Slightly\nslower");
	aboutthesame = new QRadioButton("About\nthe same");
	slightlyfaster = new QRadioButton("Slightly\nfaster");
	moderatelyfaster = new QRadioButton("Moderately\nfaster");
	muchfaster = new QRadioButton("Much\nfaster");*/

	speed0 = new QRadioButton("About\nthe same");
	speed1 = new QRadioButton("Slightly\nfaster");
	speed2 = new QRadioButton("Moderately\nfaster");
	speed3 = new QRadioButton("Much faster\n(twice as fast)");
	speed4 = new QRadioButton("More than\ntwice as fast");

	hbox = new QHBoxLayout();
	hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


	/*hbox->insertWidget(0, muchslower);
	hbox->insertWidget(1, moderatelyslower);
	hbox->insertWidget(2, slightlyslower);
	hbox->insertWidget(3, aboutthesame);
	hbox->insertWidget(4, slightlyfaster);
	hbox->insertWidget(5, moderatelyfaster);
	hbox->insertWidget(6, muchfaster);*/

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
