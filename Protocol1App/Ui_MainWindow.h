#pragma once

#include <QtWidgets/QStackedWidget>
#include <algorithm>

#include "Globals.h"
#include "StartPage.h"
#include "GoodbyePage.h"
#include "RegistryEditPage.h"
#include "TaskPage.h"
#include "PatchPage.h"
#include "RankPage.h"
#include "ComparePage.h"
#include "SingleChoicePage.h"
#include "WTAPage.h"
#include "UsagePage.h"
#include "HoursPage.h"
#include "FormPage.h"
#include "DebriefPage.h"
#include "WithdrawPage.h"


QT_BEGIN_NAMESPACE


class Ui_MainWindow
{

public:
    QWidget* centralwidget;
    QStackedWidget* stackedWidget;

    StartPage* start;
    GoodbyePage* goodbye;
    NoAdminPage* noadmin;
    RegistryEditPage* regedit;
    ModPage* mod;
    TaskPage* task1;
    TaskPage* task2;
    TaskPage* task3;
    PatchPage* patch0;
    PatchPage* patch1;
    PatchPage* patch2;
    PatchPage* patch3;
    PostTasksPage* posttasks;
    RankPage* rank;
    ComparePage* compare;
    PreWTAPage* preWTA;
    WTAPage* wta;
    UsagePage* usage;
    HoursPage* hours;
    DebriefPage* debrief;
    WithdrawPage* withdraw;
    FormPage* form;
    Failed2UploadPage* fail;
    PatchPage* upload;
    FinalPage* final;
    NotEligiblePage* noteligible;

    void setupUi(QMainWindow* MainWindow)
    {
        rec = QApplication::desktop()->screenGeometry();
        H = std::min(rec.height() / 2, rec.width() / 2);
        W = std::max(rec.height() / 2, rec.width() / 2);

        MARGIN = H / 10;
        M = MARGIN;
        LINEWIDTH = W - (2 * MARGIN);

        BUTTON_WIDTH = W / 4;
        BUTTON_HEIGHT = H / 16;

        REBOOT_AT_END = false;

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

        ///////////////////////////////////////////////////////////////////////

        start = new StartPage();
        stackedWidget->addWidget(start);

        goodbye = new GoodbyePage();
        stackedWidget->addWidget(goodbye);

        noadmin = new NoAdminPage();
        stackedWidget->addWidget(noadmin);

        regedit = new RegistryEditPage();
        stackedWidget->addWidget(regedit);

        mod = new ModPage();
        stackedWidget->addWidget(mod);

        task1 = new TaskPage("\nfrom Los Angeles, USA to New York City, USA", "the Statue of Liberty", "\"Bolero\"\nby composer Maurice Ravel");
        stackedWidget->addWidget(task1);

        task2 = new TaskPage("\nfrom Casablanca, Morocco to Cairo, Egypt", "the Eiffel Tower", "\"Rhapsody in Blue\"\nby composer George Gershwin");
        stackedWidget->addWidget(task2);


        task3 = new TaskPage("\nfrom Sydney, Australia to Perth, Australia", "the Pyramids of Giza", "\"Fantasia on a Theme by Thomas Tallis\"\nby composer Ralph Vaughan Williams");
        stackedWidget->addWidget(task3);

        patch0 = new PatchPage();
        stackedWidget->addWidget(patch0);

        patch1 = new PatchPage();
        stackedWidget->addWidget(patch1);

        patch2 = new PatchPage();
        stackedWidget->addWidget(patch2);

        patch3 = new PatchPage();
        stackedWidget->addWidget(patch3);

        posttasks = new PostTasksPage();
        stackedWidget->addWidget(posttasks);

        rank = new RankPage();
        stackedWidget->addWidget(rank);

        compare = new ComparePage();
        stackedWidget->addWidget(compare);

        preWTA = new PreWTAPage();
        stackedWidget->addWidget(preWTA);

        wta = new WTAPage();
        stackedWidget->addWidget(wta);

        usage = new UsagePage();
        stackedWidget->addWidget(usage);

        hours = new HoursPage();
        stackedWidget->addWidget(hours);

        debrief = new DebriefPage();
        stackedWidget->addWidget(debrief);

        withdraw = new WithdrawPage();
        stackedWidget->addWidget(withdraw);

        form = new FormPage();
        stackedWidget->addWidget(form);

        upload = new PatchPage();
        stackedWidget->addWidget(upload);

        fail = new Failed2UploadPage();
        stackedWidget->addWidget(fail);

        final = new FinalPage();
        stackedWidget->addWidget(final);

        noteligible = new NotEligiblePage();
        stackedWidget->addWidget(noteligible);

    } // setupUi
};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE