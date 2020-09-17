#include "ComparePage.h"
#include <QDebug>


void ComparePage::setLabels(QListWidget* listWidget) {
    QString l1text = "In your experience, how much faster was your computer during <b>" + listWidget->item(0)->text() + "</b> compared to <b>" + listWidget->item(1)->text() + "</b>?";
    label1->setTextFormat(Qt::RichText);
    label1->setText(l1text);

    QString l2text = "In your experience, how much faster was your computer during <b>" + listWidget->item(1)->text() + "</b> compared to <b>" + listWidget->item(2)->text() + "</b>?";
    label2->setTextFormat(Qt::RichText);
    label2->setText(l2text);

    // TODO if Tasks 2 & 3 are not explicitly compared, we should compare them directly.
    // NOTE I should just ask all permutations anyway...
    QString l3text = "In your experience, how much faster was your computer during <b>" + listWidget->item(0)->text() + "</b> compared to <b>" + listWidget->item(2)->text() + "</b>?";
    label3->setTextFormat(Qt::RichText);
    label3->setText(l3text);

}

void ComparePage::setupPage() {

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
    connect(this->arr1->speed0, &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->speed1, &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->speed2, &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->speed3, &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);
    connect(this->arr1->speed4, &QRadioButton::clicked, this->arr2, &ButtonArray::setVisible);

    connect(this->arr1->speed0, &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->speed1, &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->speed2, &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->speed3, &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    connect(this->arr1->speed4, &QRadioButton::clicked, this->label2, &ButtonArray::setVisible);
    
    connect(this->arr2->speed0, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->speed1, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->speed2, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->speed3, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    connect(this->arr2->speed4, &QRadioButton::clicked, this->arr3, &ButtonArray::setVisible);
    
    connect(this->arr2->speed0, &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->speed1, &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->speed2, &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->speed3, &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    connect(this->arr2->speed4, &QRadioButton::clicked, this->label3, &ButtonArray::setVisible);
    
    connect(this->arr3->speed0, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->speed1, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->speed2, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->speed3, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    connect(this->arr3->speed4, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
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
