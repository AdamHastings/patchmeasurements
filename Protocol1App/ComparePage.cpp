#include "ComparePage.h"

ComparePage::ComparePage(QWidget *parent)
	: QWidget(parent)
{

    header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M));
    header->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    header->setText("You will now answer answer some questions");


    arr1 = new ButtonArray(this);  
    arr1->setGeometry(QRect(M, 2 * M, LINEWIDTH, 1.5*M));
    arr1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    arr2 = new ButtonArray(this);
    arr2->setGeometry(QRect(M, 4 * M, LINEWIDTH, 1.5*M));
    arr2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    arr3 = new ButtonArray(this);
    arr3->setGeometry(QRect(M, 6 * M, LINEWIDTH, 1.5*M));
    arr3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    continue_btn = new QPushButton(this);
    continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");

#if QT_NO_DEBUG
    continue_btn->setEnabled(false);
#endif
}

ComparePage::~ComparePage()
{
}
