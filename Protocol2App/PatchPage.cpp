#include "PatchPage.h"
#include "Globals.h"

#include <thread>
#include <chrono>
#include <stdlib.h>


PatchPage::PatchPage(QWidget* parent)
    : QWidget(parent)
{
    label = new QLabel(this);
    label->setObjectName(QStringLiteral("patch_label"));
    label->setGeometry(QRect(M, M, LINEWIDTH - 2 * M, M * 5));
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label->setWordWrap(true);
    label->setText("Please wait while we securely send the results to the researchers.");


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
