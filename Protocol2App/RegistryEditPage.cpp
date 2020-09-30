#include "RegistryEditPage.h"
#include "Globals.h"
#include "PowerMgmt.h"


void RegistryEditPage::setupPage() {
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 3));
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setWordWrap(true);
    label->setText("As part of this experiment, we will make some temporary modifications to your computer. However, your computer's current configuration does not allow us to make these modifications. We will need to make some temporary changes to your computer and then have you reboot your device. Please note that all modifications made to your computer are temporary and will be reversed at the end of this experiment. Do you allow us to make temporary, reversible changes to your computer?");

    ok_btn = new QPushButton(this);
    ok_btn->setGeometry(QRect(M, M * 5, W / 2 - 2 * M, 2 * BUTTON_HEIGHT));
    ok_btn->setText("Make the changes now");

    notok_btn = new QPushButton(this);
    notok_btn->setGeometry(QRect(M + W / 2, M * 5, W / 2 - 2 * M, 2 * BUTTON_HEIGHT));
    notok_btn->setText("Do not make changes\n to my computer");

    done_label = new QLabel(this);
    done_label->setWordWrap(true);
    done_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    done_label->setGeometry(QRect(M * 2, M * 7, LINEWIDTH - 2 * M, M * 3));
}

void RegistryEditPage::makeConnections() {
    connect(this->ok_btn, &QPushButton::clicked, this, &RegistryEditPage::acceptOffer);
    connect(this->notok_btn, &QPushButton::clicked, this, &RegistryEditPage::declineOffer);
}

RegistryEditPage::RegistryEditPage(QWidget* parent)
    : QWidget(parent)
{
    setupPage();
    makeConnections();
}

RegistryEditPage::~RegistryEditPage()
{
}

void RegistryEditPage::acceptOffer() {
    ok_btn->setEnabled(false);
    notok_btn->setEnabled(false);
    PowerMgmt::setCsEnabled(0);
    // TODO can we set stuff in the registry and then look at it after reboots?
    done_label->setText("Done! Your computer's configuration has been changed. You will need to reboot your computer for the changes to take place. Please restart your computer and re-run this program.");
}

void RegistryEditPage::declineOffer() {
    ok_btn->setEnabled(false);
    notok_btn->setEnabled(false);
    done_label->setText("Thank you for your participation so far. Unfortunately you are not eligible to participate further and will receive no compensation. You may now close this window and delete this program.\n\nIf you ended up on this page by mistake but still want to participate in this experiment, you can simply just re-run this application.");
}
