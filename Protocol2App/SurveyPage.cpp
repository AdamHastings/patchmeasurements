#include "SurveyPage.h"
#include "Globals.h"


void SurveyPage::checkIfContinue() {
    if (
        not_enough_money->isChecked() ||
        mistrust->isChecked() ||
        privacy->isChecked() ||
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

void SurveyPage::privacy_clicked() {
    checkIfContinue();
}

void SurveyPage::other_clicked() {
    checkIfContinue();
    if (other->isChecked()) {
        other_reason->setVisible(true);
        //other_specify->setVisible(true);
        other->setText("Other (Please specify below)");
    }
    else {
        other_reason->setVisible(false);
        //other_specify->setVisible(false);
        other->setText("Other");
    }

}



void SurveyPage::setupPage() {
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 2));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    label->setWordWrap(true);
    //label->setText("Your computer's performance has been restored. This program will remove itself from your active processes and will no longer ask you daily questions. Before you are finished with this experiment, we would like to know why you declined the offer to slow your computer by " + QString::number(SLOWDOWN) + "% for 24 hours in exchange for $" + QString::number(OFFER) + ". Please select all that apply.");

    not_enough_money = new QCheckBox(this);
    not_enough_money->setGeometry(2 * M, M * 2, LINEWIDTH - 2 * M, M);
    not_enough_money->setText("Not enough money was offered");

    offerq = new QLabel(this);
    offerq->setGeometry(3 * M, M * 3, 10*M, M*1.5);
    offerq->setWordWrap(true);
    offerq->setAlignment(Qt::AlignTop);
    offerq->setText("How much money would you have to be offered for you to accept a " + QString::number(SLOWDOWN) + "% slowdown for 24 hours? Please enter the lowest dollar amount you would accept.");
    offerq->setVisible(false);

    wta_input = new QDoubleSpinBox(this);
    wta_input->setDecimals(2);
    wta_input->setSingleStep(0.01);
    wta_input->setGeometry(13 * M, M * 3, 2*M, M);
    wta_input->setMinimum(0);
    wta_input->setPrefix("$");
    wta_input->setVisible(false);

    mistrust = new QCheckBox(this);
    mistrust->setGeometry(2 * M, M * 4, LINEWIDTH - 2 * M, M);
    mistrust->setText("I'm worried about lasting damage to my computer");

    //privacy = new QCheckBox(this);
    //privacy->setGeometry(2 * M, M * 5, LINEWIDTH - 2 * M, M);
    //privacy->setText("I'm no longer comfortable with the data being collected during this experiment");

    other = new QCheckBox(this);
    other->setGeometry(2 * M, M * 6, LINEWIDTH - 2 * M, M);
    other->setText("Other");

    /*other_specify = new QLabel(this);
    other_specify->setGeometry(4 * M, M * 6, 4 * M, M);
    other_specify->setText("Please specify below");
    other_specify->setVisible(false);*/

    other_reason = new QTextEdit(this);
    other_reason->setGeometry(3 * M, 7 * M, LINEWIDTH - 4 * M, M);
    other_reason->setVisible(false);

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
    //#if QT_NO_DEBUG
    continue_btn->setEnabled(false);
    //#endif
}

void SurveyPage::makeConnections() {
    connect(not_enough_money, &QPushButton::clicked, this, &SurveyPage::not_enough_money_clicked);
    connect(mistrust, &QPushButton::clicked, this, &SurveyPage::mistrust_clicked);
    //connect(privacy, &QPushButton::clicked, this, &SurveyPage::privacy_clicked);
    connect(other, &QPushButton::clicked, this, &SurveyPage::other_clicked);
}

SurveyPage::SurveyPage(QWidget *parent)
	: QWidget(parent)
{
    setupPage();
    makeConnections();
}

//void SurveyPage::firstOffer() {
//    label->setText("Your computer's performance will not be modified. Before you are finished with this experiment, we would like to know why you declined the offer to slow your computer by " + QString::number(SLOWDOWN) + "% for 24 hours in exchange for $" + QString::number(OFFER) + "? Please select all that apply.");
//}

void SurveyPage::resetPage(int days) {
    if (days == TOTAL_DAYS) {
        label->setText("Your computer's performance will not be modified. Before you are finished, please let us know why you declined to slow your computer by " + QString::number(SLOWDOWN) + "% for 24 hours in exchange for $" + QString::number(OFFER) + ". Please select all that apply.");
    }
    else {
        label->setText("Your computer's performance has been restored. Before you are finished, please let us know why you declined to slow your computer by " + QString::number(SLOWDOWN) + "% for 24 hours in exchange for $" + QString::number(OFFER) + ". Please select all that apply.");
    }
}

SurveyPage::~SurveyPage()
{
}
