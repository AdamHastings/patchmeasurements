#include "Check4Cheating.h"
#include "Globals.h"

void Check4Cheating::checkIfContinue() {
	if (honest_btn->isChecked()) {
		continue_btn->setEnabled(true);
		ask_for_details->setVisible(false);
		details->setVisible(false);
	}
	else if (cheated_btn->isChecked()) {
		continue_btn->setEnabled(true);
		ask_for_details->setVisible(true);
		details->setVisible(true);
	}
	else {
		continue_btn->setEnabled(false);
	}
}

Check4Cheating::Check4Cheating(QWidget *parent)
	: QWidget(parent)
{
	label = new QLabel(this);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignJustify);
	label->setGeometry(M, M, LINEWIDTH, 3 * M);
	label->setText("During this experiment, your computer's speed was monitored to ensure that you were not cheating the experiment by manually reversing the speed changes made to your computer. Our anti-cheating measures were robust, but it is possible that a motivated participant could have found a way around our anti-cheat mechanisms. If such a participant's daily responses were used for research purposes, it could undermine any conclusions made by the researchers and could harm the scientific community and society at large. For these reasons, we are asking you to truthfully report if you cheated during this experiment by deliberately undoing the slowdowns made to your computer.\n\nPlease note that if our anti-cheating mechanisms were not able to detect your cheating, then your response here will NOT affect any money you may have earned during this experiment. Likewise, you will not get in trouble, so there is no incentive to be dishonest.");

	honest_btn = new QRadioButton(this);
	honest_btn->setGeometry(2 * M, M * 4, LINEWIDTH - 2 * M, M);
	honest_btn->setText("I did not cheat during this experiment");

	cheated_btn = new QRadioButton(this);
	cheated_btn->setGeometry(2 * M, M * 5, LINEWIDTH - 2 * M, M);
	cheated_btn->setText("I cheated during this experiment");

	ask_for_details = new QLabel(this);
	ask_for_details->setGeometry(2 * M, M * 6, LINEWIDTH - 2 * M, M);
	ask_for_details->setWordWrap(true);
	ask_for_details->setText("How were you able to cheat the experiment? Recall that if your cheated went undetected, your response here will NOT affect any money you may have earned. Consider this an opportunity for you to brag about how clever you are.");
	ask_for_details->setVisible(false);

	details = new QTextEdit(this);
	details->setGeometry(2 * M, M * 7, LINEWIDTH - 2 * M, M);
	details->setVisible(false);

	continue_btn = new QPushButton(this);
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
	//#if QT_NO_DEBUG
	continue_btn->setEnabled(false);
	//#endif

	connect(this->honest_btn, &QRadioButton::isChecked, this, &Check4Cheating::checkIfContinue);
	connect(this->cheated_btn, &QRadioButton::isChecked, this, &Check4Cheating::checkIfContinue);
	//connect(this->details, &QTextEdit::textChanged, this, &Check4Cheating::checkIfContinue);
}

Check4Cheating::~Check4Cheating()
{
}
