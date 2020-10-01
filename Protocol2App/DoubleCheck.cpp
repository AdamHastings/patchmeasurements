#include "DoubleCheck.h"
#include "Globals.h"
#include "RegistryUtils.h"
#include "DropBox.h"
#include "PowerMgmt.h"

#include <iomanip>
#include <ctime>
#include <sstream>

QString DoubleCheck::getTimestamp() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
    return QString::fromStdString(str);
}

DoubleCheck::DoubleCheck(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 3));
    label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    label->setWordWrap(true);

    confirm_btn = new QPushButton(this);
    confirm_btn->setGeometry(QRect(M, M * 5, W / 2 - 2 * M, 2 * BUTTON_HEIGHT));
    confirm_btn->setText("Yes, this is correct");

    mistake_btn = new QPushButton(this);
    mistake_btn->setGeometry(QRect(M + W / 2, M * 5, W / 2 - 2 * M, 2 * BUTTON_HEIGHT));
    mistake_btn->setText("I made a mistake! Please take me\nback to the previous page.");

    done_label = new QLabel(this);
    done_label->setWordWrap(true);
    done_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    done_label->setGeometry(QRect(M * 2, M * 7, LINEWIDTH - 2 * M, M * 3));

   /* connect(this->confirm_btn, &QPushButton::clicked, this, &DoubleCheck::makeChoice);
    connect(this->mistake_btn, &QPushButton::clicked, this, &DoubleCheck::makeChoice);*/
}

DoubleCheck::~DoubleCheck()
{
}


//// Accept /////////////////////////////////////////////////////////////////////

void DoubleCheckAccept::uploadChoice() {
    QString filename = getTimestamp();

    QString contents = "";
    contents.append("choice,accept\n");

    /*auto current_ACProcThrottleMin = PowerMgmt::*/

    // for i in map, append kv pairs
}

DoubleCheckAccept::DoubleCheckAccept(QWidget* parent) : DoubleCheck(parent)
{
    label->setText("You've selected to continue slowing down your computer by " + QString::number(SLOWDOWN) + "% for another 24 hours in exchange for $" + QString::number(OFFER) + ".\nIs this choice correct?");
    // TODO "is this choice correct" sounds weird. But "Are you sure this is what you want to do?" may influence the psychology of the participants. Ask...

    connect(this->confirm_btn, &QPushButton::clicked, this, &DoubleCheckAccept::uploadChoice);
}


//// Decline //////////////////////////////////////////////////////////////////

void DoubleCheckDecline::uploadChoice() {
    // TODO upload to Dropbox
}

void DoubleCheckDecline::restoreDefaults() {
    // TODO restore defaults
}

DoubleCheckDecline::DoubleCheckDecline(QWidget* parent) : DoubleCheck(parent)
{
    label->setText("You've selected to restore your computer to full performance. This selection means that you will be ineligible to earn any more money from this experiment. If you confirm your choice below, your computer will be restored to full performance, this app will close and you will no longer be asked daily to choose between computer performance and money. Is this choice correct?");
}


