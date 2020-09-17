#pragma once

#include <QtWidgets/QStackedWidget>
#include <algorithm>

#include "Globals.h"
#include "StartPage.h"
#include "GoodbyePage.h"
#include "TaskPage.h"
#include "PatchPage.h"
#include "RankPage.h"
#include "ComparePage.h"
#include "SingleChoicePage.h"
#include "WTAPage.h"


QT_BEGIN_NAMESPACE


class Ui_MainWindow
{

public:
    QWidget* centralwidget;
    QStackedWidget* stackedWidget;

    GoodbyePage* goodbye;
    StartPage* start;
    TaskPage* task1;
    TaskPage* task2;
    TaskPage* task3;
    PatchPage* patch1;
    PatchPage* patch2;
    PatchPage* patch3;
    PostTasksPage* posttasks;
    RankPage* rank;
    ComparePage* compare;
    PreWTAPage* preWTA;
    WTAPage* wta;
    FinalPage* final;

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

        task1 = new TaskPage("\nfrom Los Angeles, USA to New York City, USA", "Low Library", "\"Bolero\"\nby composer Maurice Ravel");
        stackedWidget->addWidget(task1);

        task2 = new TaskPage("\nfrom Casablanca, Morocco to Cairo, Egypt", "the Alma Mater statue", "\"Rhapsody in Blue\"\nby composer George Gershwin");
        stackedWidget->addWidget(task2);


        task3 = new TaskPage("\nfrom Sydney, Australia to Perth, Australia", "Low Library", "\"Fantasia on a Theme by Thomas Tallis\"\nby composer Ralph Vaughan Williams");
        stackedWidget->addWidget(task3);

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

        final = new FinalPage();
        stackedWidget->addWidget(final);

    } // setupUi
};

namespace Ui {
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE