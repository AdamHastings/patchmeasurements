#include "SingleChoicePage.h"
#include "Globals.h"
#include <QFont>

SingleChoicePage::SingleChoicePage(QWidget* parent)
    : QWidget(parent)
{

    QFont font = QFont();
    //font.setPointSize(12);
    //font.setWordSpacing(M / 10);

    label = new QLabel(this);
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setGeometry(QRect(2* M, M, LINEWIDTH - 2*M, M * 6));
    label->setWordWrap(true);
    label->setFont(font);

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
}

SingleChoicePage::~SingleChoicePage()
{
}