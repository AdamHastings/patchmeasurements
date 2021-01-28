#include "PatchPage.h"
#include "Globals.h"

#include <thread>
#include <chrono>
#include <stdlib.h>


int PatchPage::patchCount = 0;

PatchPage::PatchPage(QWidget *parent)
	: QWidget(parent)
{
    label = new QLabel(this);
    label->setObjectName(QStringLiteral("patch_label"));
    label->setGeometry(QRect(M, M, LINEWIDTH-2*M, M * 5));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setWordWrap(true);
    if (patchCount == 0)
        label->setText("We will now make some modifications to your computer. These modifications are only temporary and will end once this experiment concludes.");
    else if (patchCount == 1 || patchCount == 2)
        label->setText("We will now undo the previous modifications to your computer and apply some new ones. These modifications are only temporary and will end once this experiment concludes.");
    else if (patchCount == 3)
        label->setText("We will now undo all modifications made to your computer.");
    else
        label->setText("Please wait while survey responses are securely sent to the researchers.");
    
    patchCount++;


    progress_bar = new QProgressBar(this);
    progress_bar->setGeometry(QRect(W / 2 - 4 * M, M * 5, 8 * M, M));
    progress_bar->setMinimum(0);
    progress_bar->setMaximum(100);
    progress_bar->setValue(0);

    done_label = new QLabel(this);
    done_label->setGeometry(QRect((W - BUTTON_WIDTH) / 2, M * 6, BUTTON_WIDTH, BUTTON_HEIGHT));
    done_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    continue_btn = new QPushButton(this);
    continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");

#if QT_NO_DEBUG
    continue_btn->setEnabled(false);
#endif
}

void PatchPage::fillBar() {
    int MAGIC_THRES = 45;

    for (int i = 0; i < MAGIC_THRES; i++) {
        progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i = MAGIC_THRES; i <= 100; i++) {
        progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void PatchPage::slowFillBar() {
    for (int i = 0; i <= 100; i++) {
        progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void PatchPage::fillFirstHalf() {
    for (int i = 0; i < 50; i++) {
        progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

void PatchPage::fillSecondHalf() {
    for (int i = 50; i <= 100; i++) {
        progress_bar->setValue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

}

PatchPage::~PatchPage()
{
}
