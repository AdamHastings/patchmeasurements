#include "DebriefPage.h"
#include "Globals.h"

DebriefPage::DebriefPage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(QRect(M, M, LINEWIDTH, M * 7));
    label->setAlignment(Qt::AlignJustify | Qt::AlignTop);
    label->setWordWrap(true);
    label->setText("As previously stated, this computer was slowed down by 30% during <Task X>. You were not informed of this because part of what this experiment aimed to discover was whether or not this slowdown is perceptible to computer users. The reason for this deception was so that you would not pay extra attention to your device's performance; this was important to the integrity of this experiment because it mimics how computer hardware companies currently fix security issues in their products. Namely, computer hardware companies have recently been issuing fixes to security problems by issuing updates to their customers which can degrade performance by up to 30% in some reported cases. This experiment was designed to find out if such a slowdown makes a noticeable difference to everyday computer users. In addition, this experiment was designed to elicit how much you value this amount of performance in terms of US dollars.\n\nIf you have additional questions about this deception, you may contact the researchers at hastings - experiment@cs.columbia.edu or the Human Resource Protection Office at 212-305-5883 or askirb@columbia.edu\n\nBecause this experiment involved deception, you have the right as a research participant to withdraw from the study. You will not be compensated if you withdraw from this experiment. Do you wish to withdraw ? ");

    yes_btn = new QPushButton(this);
    yes_btn->setGeometry(W / 2 + M, M * 7, 4 * M, M);
    yes_btn->setText("Yes, please withdraw me\nfrom this experiment");

    no_btn = new QPushButton(this);
    no_btn->setGeometry(W / 2 - 5 * M, M * 7, 4 * M, M);
    no_btn->setText("No, do not withdraw me\nfrom this experiment");

    

    //yes2_btn = new QPushButton(this);
    //yes2_btn->setGeometry(W / 2 + M, M * 8.5, 4 * M, BUTTON_HEIGHT);
    //yes2_btn->setText("Yes, I am sure");

    //no2_btn = new QPushButton(this);
    //no2_btn->setGeometry(W / 2 - 5 * M, M * 8.5, 4 * M, BUTTON_HEIGHT);
    //no2_btn->setText("No, I made a mistake");
    



}

DebriefPage::~DebriefPage()
{
}
