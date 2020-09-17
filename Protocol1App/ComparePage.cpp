#include "ComparePage.h"
#include <QDebug>


void ComparePage::setLabels(QListWidget* listWidget) {
    QString l1text = "In your experience, how much faster was your computer during " + listWidget->item(0)->text() + " compared to " + listWidget->item(1)->text() + "?";
    label1->setText(l1text);

    QString l2text = "In your experience, how much faster was your computer during " + listWidget->item(1)->text() + " compared to " + listWidget->item(2)->text() + "?";
    label2->setText(l2text);

    // TODO if Tasks 2 & 3 are not explicitly compared, we should compare them directly.
    // NOTE I should just ask all permutations anyway...
    QString l3text = "In your experience, how much faster was your computer during " + listWidget->item(0)->text() + " compared to " + listWidget->item(2)->text() + "?";
    label3->setText(l3text);

}

void ComparePage::setupPage() {
    /*header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M));
    header->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    header->setText("You will now answer answer some questions");*/

    label1 = new QLabel(this);
    label1->setGeometry(QRect(M, M, LINEWIDTH, M));
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    arr1 = new ButtonArray(this);
    arr1->setGeometry(QRect(M, 1.5 * M, LINEWIDTH, 1.5 * M));
    arr1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    label2 = new QLabel(this);
    label2->setGeometry(QRect(M, 3.5 * M, LINEWIDTH, M));
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    label2->setVisible(false);
    
    arr2 = new ButtonArray(this);
    arr2->setGeometry(QRect(M, 4 * M, LINEWIDTH, 1.5 * M));
    arr2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    arr2->setVisible(false);

    label3 = new QLabel(this);
    label3->setGeometry(QRect(M, 6 * M, LINEWIDTH, M));
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    label3->setVisible(false);

    arr3 = new ButtonArray(this);
    arr3->setGeometry(QRect(M, 6.5 * M, LINEWIDTH, 1.5 * M));
    arr3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    arr3->setVisible(false);

    continue_btn = new QPushButton(this);
    continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
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

    connect(this->arr1->muchslower,       &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->moderatelyslower, &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->slightlyslower,   &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->aboutthesame,     &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->slightlyfaster,   &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->moderatelyfaster, &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->muchfaster,       &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);

    connect(this->arr2->muchslower,       &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->moderatelyslower, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->slightlyslower,   &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->aboutthesame,     &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->slightlyfaster,   &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->moderatelyfaster, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->muchfaster,       &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);

    connect(this->arr2->muchslower,       &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->moderatelyslower, &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->slightlyslower,   &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->aboutthesame,     &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->slightlyfaster,   &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->moderatelyfaster, &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->muchfaster,       &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);

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
