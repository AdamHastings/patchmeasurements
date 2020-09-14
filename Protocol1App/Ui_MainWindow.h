#pragma once
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSpinBox>
#include <QFont>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>

#include "GoodbyePage.h"
#include "Globals.h"

#include <algorithm>

QT_BEGIN_NAMESPACE


class Ui_MainWindow
{

private:
    /*QRect rec = QApplication::desktop()->screenGeometry();
    const int H = std::min(rec.height() / 2, rec.width() / 2);
    const int W = std::max(rec.height() / 2, rec.width() / 2);

    const int MARGIN = H / 10;
    const int M = MARGIN;
    const int LINEWIDTH = W - (2 * MARGIN);

    const int BUTTON_WIDTH = W / 4;
    const int BUTTON_HEIGHT = H / 16;*/

public:
    QWidget* centralwidget;
    QStackedWidget* stackedWidget;

    QWidget* start_page;
    QLabel* intro_label;
    QPushButton* consent_btn;
    QLabel* outline_label;
    QLabel* consent_label;
    QPushButton* not_consent_btn;

    QWidget* start;
    QWidget* goodbye;

    void setupUi(QMainWindow* MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));

        //// main setup ///////////////////////////////////////////////////////

        MainWindow->setMinimumSize(QSize(W, H));
        MainWindow->setMaximumSize(QSize(W, H));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(W, H));
        centralwidget->setMaximumSize(QSize(W, H));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, W, H));
        stackedWidget->setMinimumSize(QSize(W, H));
        stackedWidget->setMaximumSize(QSize(W, H));

        //// start page ///////////////////////////////////////////////////////

        start_page = new QWidget();
        start_page->setObjectName(QStringLiteral("start_page"));

        intro_label = new QLabel(start_page);
        intro_label->setObjectName(QStringLiteral("intro_label"));
        intro_label->setGeometry(QRect(MARGIN, MARGIN, LINEWIDTH, MARGIN * 3));
        intro_label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
        intro_label->setWordWrap(true);

        outline_label = new QLabel(start_page);
        outline_label->setObjectName(QStringLiteral("outline_label"));
        outline_label->setGeometry(QRect(MARGIN, MARGIN * 4, LINEWIDTH, MARGIN * 3));
        outline_label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
        outline_label->setWordWrap(true);

        consent_label = new QLabel(start_page);
        consent_label->setObjectName(QStringLiteral("consent_label"));
        consent_label->setGeometry(QRect(MARGIN, MARGIN * 7, LINEWIDTH, MARGIN));
        consent_label->setAlignment(Qt::AlignJustify | Qt::AlignVCenter);
        consent_label->setWordWrap(true);

        consent_btn = new QPushButton(start_page);
        consent_btn->setObjectName(QStringLiteral("consent_btn"));
        consent_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH - M, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));

        not_consent_btn = new QPushButton(start_page);
        not_consent_btn->setObjectName(QStringLiteral("not_consent_btn"));
        not_consent_btn->setGeometry(QRect(W / 2 + M, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));

        stackedWidget->addWidget(start_page);

        intro_label->setText("Thank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 20 minutes to complete.");
        consent_btn->setText("I consent");
        outline_label->setText("This experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will first have you complete some simple tasks with these modifications turned off. Later, we will turn on these modifications and ask you to complete the same set of tasks.");
        consent_label->setText("Do you consent to participate in this study? You may exit the experiment at any point.");
        not_consent_btn->setText("I do not consent");


        ///////////////////////////////////////
        //goodbye_page = new QWidget();
        //goodbye_page->setObjectName(QStringLiteral("goodbye_page"));
        //stackedWidget->addWidget(goodbye_page);

        goodbye = new GoodbyePage();
        stackedWidget->addWidget(goodbye);

        //
        //goodbye_label = new QLabel(goodbye_page);
        //goodbye_label->setObjectName(QStringLiteral("goodbye_label"));
        //goodbye_label->setGeometry(QRect(M, M, LINEWIDTH, M * 4));
        //goodbye_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //goodbye_label->setWordWrap(true);
        //goodbye_label->setText("Thank you for your participation. You may now exit this window.");


    } // setupUi
};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE