//#include "ButtonArray_old.h"
//
//ButtonArray::ButtonArray(QWidget *parent)
//	: QButtonGroup(parent)
//{
//
//	box = new QGroupBox();
//
//	muchslower = new QRadioButton("Much\nslower");
//	moderatelyslower = new QRadioButton("Moderately\nslower");
//	slightlyslower = new QRadioButton("Slightly\nslower");
//	aboutthesame = new QRadioButton("About\nthe same");
//	slightlyfaster = new QRadioButton("Slightly\nfaster");
//	moderatelyfaster = new QRadioButton("Moderately\nfaster");
//	muchfaster = new QRadioButton("Much\nfaster");
//
//	vbox = new QVBoxLayout();
//	hbox = new QHBoxLayout();
//
//	hbox->addWidget(muchfaster);
//	hbox->addWidget(moderatelyslower);
//	hbox->addWidget(slightlyslower);
//	hbox->addWidget(aboutthesame);
//	hbox->addWidget(slightlyfaster);
//	hbox->addWidget(moderatelyfaster);
//	hbox->addWidget(muchfaster);
//	hbox->addStretch(1);
//	//hbox->setGeometry(QRect(M, M, LINEWIDTH, M));
//	box->setLayout(hbox);
//}
//
//ButtonArray::~ButtonArray()
//{
//}
