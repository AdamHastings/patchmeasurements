#include "SingleChoicePage.h"
#include "Globals.h"

SingleChoicePage::SingleChoicePage(QWidget *parent)
	: QWidget(parent)
{

    label = new QLabel(this);
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 6));

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
}

SingleChoicePage::~SingleChoicePage()
{
}
