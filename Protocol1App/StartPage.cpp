#include "StartPage.h"
#include "Globals.h"

StartPage::StartPage(QWidget *parent)
	: QWidget(parent)
{
    /*start_page = new QWidget();
    start_page->setObjectName(QStringLiteral("start_page"));*/

    intro_label = new QLabel(this);
    intro_label->setObjectName(QStringLiteral("intro_label"));
    intro_label->setGeometry(QRect(MARGIN, MARGIN, LINEWIDTH, MARGIN * 3));
    intro_label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    intro_label->setWordWrap(true);

    outline_label = new QLabel(this);
    outline_label->setObjectName(QStringLiteral("outline_label"));
    outline_label->setGeometry(QRect(MARGIN, MARGIN * 4, LINEWIDTH, MARGIN * 3));
    outline_label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    outline_label->setWordWrap(true);

    consent_label = new QLabel(this);
    consent_label->setObjectName(QStringLiteral("consent_label"));
    consent_label->setGeometry(QRect(MARGIN, MARGIN * 7, LINEWIDTH, MARGIN));
    consent_label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
    consent_label->setWordWrap(true);

    consent_btn = new QPushButton(this);
    consent_btn->setObjectName(QStringLiteral("consent_btn"));
    consent_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH - M, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));

    not_consent_btn = new QPushButton(this);
    not_consent_btn->setObjectName(QStringLiteral("not_consent_btn"));
    not_consent_btn->setGeometry(QRect(W / 2 + M, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
    not_consent_btn->setText("I do not consent");

    //stackedWidget->addWidget(start_page);

    intro_label->setText("Thank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 20 minutes to complete.");
    consent_btn->setText("I consent");
    outline_label->setText("This experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will first have you complete some simple tasks with these modifications turned off. Later, we will turn on these modifications and ask you to complete the same set of tasks.");
    consent_label->setText("Do you consent to participate in this study? You may exit the experiment at any point.");

}

StartPage::~StartPage()
{
}
