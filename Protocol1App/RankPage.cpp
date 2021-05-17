#include "RankPage.h"
#include "Globals.h"
#include <QSize>
#include <vector>
#include <QLabel>
#include <QPixMap>
#include <QHBoxLayout>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::rand, std::srand
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock



RankPage::RankPage(QWidget* parent)
	: QWidget(parent)

{

	label = new QLabel("Please select the option that most closely matches your experience while completing the tasks.", this);
	label->setAlignment(Qt::AlignVCenter | Qt::AlignJustify);
	label->setWordWrap(true);
	label->setGeometry(QRect(M, M/2, LINEWIDTH, 2 * M));

	task2_slower = new QRadioButton(this);
	nodifference = new QRadioButton(this);
	task3_slower = new QRadioButton(this);

	task2_slower->setText("My computer's speed felt slower during Task 2 than during Task 3");
	task3_slower->setText("My computer's speed felt slower during Task 3 than during Task 2");
	nodifference->setText("My computer's speed felt the same during Task 2 and Task 3"); 

	int rand1 = rand() % 3;
	int rand2 = rand() % 2;

	int t2s_offset = 0, t3s_offset = 0, ndf_offset = 0;

	// dumb algorithm but it works
	if (rand1 == 0) {
		t2s_offset = 0;
		if (rand2) {
			t3s_offset = 1;
			ndf_offset = 2;
		}
		else {
			t3s_offset = 2;
			ndf_offset = 1;
		}
	}
	else if (rand1 == 1) {
		t2s_offset = 1;
		if (rand2) {
			t3s_offset = 0;  
			ndf_offset = 2;
		}
		else {
			t3s_offset = 2;
			ndf_offset = 0;
		}
	}
	else {
		t2s_offset = 2;
		if (rand2) {
			t3s_offset = 0;
			ndf_offset = 1;
		}
		else {
			t3s_offset = 1;
			ndf_offset = 0;
		}
	}

	t2s_offset = (t2s_offset + 3) * M;
	t3s_offset = (t3s_offset + 3) * M;
	ndf_offset = (ndf_offset + 3) * M;


	task2_slower->setGeometry(2*M, t2s_offset, LINEWIDTH-2*M, M);
	task3_slower->setGeometry(2*M, t3s_offset, LINEWIDTH-2*M, M);
	nodifference->setGeometry(2 * M, ndf_offset, LINEWIDTH - 2 * M, M);

	continue_btn = new QPushButton(this);
	continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 7, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");
	continue_btn->setEnabled(false);


	connect(task2_slower, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
	connect(task3_slower, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
	connect(nodifference, &QRadioButton::clicked, this->continue_btn, &QPushButton::setEnabled);
}

RankPage::~RankPage()
{
}

AttentionCheckPage::AttentionCheckPage(QWidget* parent) : RankPage(parent) {
	label->setText("Please select the option that is first (highest) in the list below regardless of what most closely matches your experience while completing the tasks.");
	label->setAlignment(Qt::AlignVCenter | Qt::AlignJustify);
	label->setWordWrap(true);
	label->setGeometry(QRect(M, M / 2, LINEWIDTH, 2 * M));

	task2_slower->setText("Task 1 was the hardest");
	task3_slower->setText("Task 2 was the hardest");
	nodifference->setText("Task 3 was the hardest");

	task2_slower->setGeometry(2 * M, 3 * M, LINEWIDTH - 2 * M, M);
	task3_slower->setGeometry(2 * M, 4 * M, LINEWIDTH - 2 * M, M);
	nodifference->setGeometry(2 * M, 5 * M, LINEWIDTH - 2 * M, M);
}
