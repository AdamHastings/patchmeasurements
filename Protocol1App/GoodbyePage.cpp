#include "GoodbyePage.h"
#include "Globals.h"
#include <QDebug>

GoodbyePage::GoodbyePage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(M*2, 4*M, LINEWIDTH-2*M, M * 6));
    label->setAlignment(Qt::AlignJustify);
    label->setWordWrap(true);
    label->setText("Thank you for your participation. Unfortunately, you are not eligible to participate in this experiment. You may now exit this window. You may also delete this program from your computer.\n\nIf you ended up on this page by mistake but still want to participate in this experiment, you can simply just re-run this application.");
}

GoodbyePage::~GoodbyePage()
{
}
