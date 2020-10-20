#include "SurveyPage.h"
#include "Globals.h"


void SurveyPage::checkIfContinue() {
    if (
        not_enough_money->isChecked() ||
        mistrust->isChecked() ||
        other->isChecked()
        ) {
        continue_btn->setEnabled(true);
    }
    else {
        continue_btn->setDisabled(true);
    }
}

void SurveyPage::not_enough_money_clicked() {
    checkIfContinue();
    if (not_enough_money->isChecked()) {
        offerq->setVisible(true);
        wta_input->setVisible(true);
    }
    else {
        offerq->setVisible(false);
        wta_input->setVisible(false);
    }
}

void SurveyPage::mistrust_clicked() {
    checkIfContinue();
}

void SurveyPage::other_clicked() {
    checkIfContinue();
}



void SurveyPage::setupPage() {
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 2));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    label->setWordWrap(true);
    label->setText("Your computer's performance has been restored. This program will remove itself from your active processes and will no longer ask you daily questions. Before you are finished with this experiment, we would like to know why you declined the offer to slow your computer by " + QString::number(SLOWDOWN) + "% for 24 hours in exchange for $" + QString::number(OFFER) + "? Please select all that apply.");

    not_enough_money = new QCheckBox(this);
    not_enough_money->setGeometry(2 * M, M * 1.5, LINEWIDTH - 2 * M, 2 * M);
    not_enough_money->setText("Not enough money was offered");

    offerq = new QLabel(this);
    offerq->setGeometry(3 * M, M * 3, 10*M, M);
    offerq->setWordWrap(true);
    offerq->setText("How much money would you have to be offered to accept a " + QString::number(SLOWDOWN) + "% slowdown? Please enter the lowest dollar amount you would accept.");
    offerq->setVisible(false);

    wta_input = new QSpinBox(this);
    wta_input->setGeometry(13 * M, M * 3, 2*M, M);
    wta_input->setMinimum(0);
    wta_input->setPrefix("$");
    wta_input->setVisible(false);

    mistrust = new QCheckBox(this);
    mistrust->setGeometry(2 * M, M * 3.5, LINEWIDTH - 2 * M, 2 * M);
    mistrust->setText("I'm worried about lasting damage to my computer");

    other = new QCheckBox(this);
    other->setGeometry(2 * M, M * 5, LINEWIDTH - 2 * M, 2 * M);
    other->setText("Other");

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
    //#if QT_NO_DEBUG
    continue_btn->setEnabled(false);
    //#endif
}

void SurveyPage::makeConnections() {
    connect(not_enough_money, &QPushButton::clicked, this, &SurveyPage::not_enough_money_clicked);
    connect(mistrust, &QPushButton::clicked, this, &SurveyPage::mistrust_clicked);
    connect(other, &QPushButton::clicked, this, &SurveyPage::other_clicked);
}

SurveyPage::SurveyPage(QWidget *parent)
	: QWidget(parent)
{
    setupPage();
    makeConnections();
}

void SurveyPage::firstOffer() {
    label->setText("Your computer's performance will not be modified. Before you are finished with this experiment, we would like to know why you declined the offer to slow your computer by " + QString::number(SLOWDOWN) + "% for 24 hours in exchange for $" + QString::number(OFFER) + "? Please select all that apply.");
}

SurveyPage::~SurveyPage()
{
}
