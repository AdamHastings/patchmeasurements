#include "PatchPage.h"
#include "Globals.h"

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
    else if (patchCount == 1)
        label->setText("We will now undo the previous modifications to your computer and apply some new ones. These modifications are only temporary and will end once this experiment concludes.");
    else
        label->setText("We will now undo all modifications made to your computer.");
    
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

PatchPage::~PatchPage()
{
}
