#include "ComparePage.h"
#include <QDebug>

void ComparePage::setupPage() {
    header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M));
    header->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    header->setText("You will now answer answer some questions");


    arr1 = new ButtonArray(this);
    arr1->setGeometry(QRect(M, 2 * M, LINEWIDTH, 1.5 * M));
    arr1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    arr2 = new ButtonArray(this);
    arr2->setGeometry(QRect(M, 4 * M, LINEWIDTH, 1.5 * M));
    arr2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    arr2->setVisible(false);

    arr3 = new ButtonArray(this);
    arr3->setGeometry(QRect(M, 6 * M, LINEWIDTH, 1.5 * M));
    arr3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    arr3->setVisible(false);

    continue_btn = new QPushButton(this);
    continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
#if QT_NO_DEBUG
    continue_btn->setEnabled(false);
#endif
}

void ComparePage::makeConnections() {
    connect(this->arr1->muchslower,       &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->moderatelyslower, &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->slightlyslower,   &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->aboutthesame,     &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->slightlyfaster,   &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->moderatelyfaster, &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->muchfaster,       &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);

    connect(this->arr2->muchslower,       &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->moderatelyslower, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->slightlyslower,   &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->aboutthesame,     &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->slightlyfaster,   &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->moderatelyfaster, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->muchfaster,       &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);

    connect(this->arr3->muchslower,       &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->moderatelyslower, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->slightlyslower,   &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->aboutthesame,     &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->slightlyfaster,   &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->moderatelyfaster, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->muchfaster,       &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
}

ComparePage::ComparePage(QWidget *parent)
	: QWidget(parent)
{
    setupPage();
    makeConnections();
}

ComparePage::~ComparePage()
{
}
