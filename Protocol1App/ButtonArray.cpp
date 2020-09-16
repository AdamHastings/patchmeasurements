#include "ButtonArray.h"

ButtonArray::ButtonArray(QWidget *parent)
	: QGroupBox(parent)
{
	//box = new QGroupBox();

	muchslower = new QRadioButton("Much\nslower");
	moderatelyslower = new QRadioButton("Moderately\nslower");
	slightlyslower = new QRadioButton("Slightly\nslower");
	aboutthesame = new QRadioButton("About\nthe same");
	slightlyfaster = new QRadioButton("Slightly\nfaster");
	moderatelyfaster = new QRadioButton("Moderately\nfaster");
	muchfaster = new QRadioButton("Much\nfaster");

	hbox = new QHBoxLayout();
	hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


	hbox->insertWidget(0, muchslower);
	hbox->insertWidget(1, moderatelyslower);
	hbox->insertWidget(2, slightlyslower);
	hbox->insertWidget(3, aboutthesame);
	hbox->insertWidget(4, slightlyfaster);
	hbox->insertWidget(5, moderatelyfaster);
	hbox->insertWidget(6, muchfaster);
	hbox->setSpacing(50);
	this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	this->setLayout(hbox);

}

ButtonArray::~ButtonArray()
{
}
