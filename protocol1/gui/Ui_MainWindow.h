/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QFont>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>

#include "Pages.h"


QT_BEGIN_NAMESPACE

class Ui_MainWindow
{

private:
    QRect rec = QApplication::desktop()->screenGeometry();
    const int H = rec.height()/3;
    const int W = rec.width()/3;

    const int MARGIN = H/10;
    const int M = MARGIN;
    const int LINEWIDTH = W - (2*MARGIN);

    const int BUTTON_WIDTH = W/4;
    const int BUTTON_HEIGHT = H/16;

public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    
    QWidget *start_page;
    QLabel *intro_label;
    QPushButton *consent_btn;
    QLabel *outline_label;
    QLabel *consent_label;
    QPushButton *not_consent_btn;
    QWidget *consent_page;
    
    QWidget *goodbye_page;
    QLabel *goodbye_label;
    QPushButton *goodbye_btn;
    
    QWidget *task1_page;
    QLabel *task1_label;
    QPushButton *task1_continue_btn;

    QWidget *patch_page;
    QLabel *patch_label;
    QLabel *patch_done_label;
    QProgressBar *patch_progress_bar;
    QPushButton *patch_continue_btn;

    QWidget *task2_page;
    QLabel *task2_label;
    QPushButton *task2_continue_btn;

    QWidget *q1_page;
    QLabel *q1_label;
    QButtonGroup *q1_button_group;
    QRadioButton *q1_yes_btn;
    QRadioButton *q1_no_btn;
    QPushButton *q1_continue_btn;

    QWidget *q2_page;
    QLabel *q2_label;
    QTextEdit *q2_input;
    QPushButton *q2_continue_btn;

    QWidget *q3_page;
    QLabel *q3_label;
    QButtonGroup *q3_button_group;
    QRadioButton *q3_yes_btn;
    QRadioButton *q3_no_btn;
    QPushButton *q3_continue_btn;

    QWidget *q4_page;
    QLabel *q4_label;
    QLineEdit *q4_input;
    QPushButton *q4_continue_btn;

    QWidget *wta_page;
    QLabel *wta_label;
    QLabel *wta_offer;
    QLabel *wta_disclaimer_label;
    QPushButton *wta_yes_btn;
    QPushButton *wta_no_btn;



    void config_goodbye_page() {

    }

    void configPages() {
        config_goodbye_page();

    }

    void setupUi(QMainWindow *MainWindow)
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
        intro_label->setGeometry(QRect(MARGIN, MARGIN, LINEWIDTH, MARGIN*3));
        intro_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        intro_label->setWordWrap(true);
              
        outline_label = new QLabel(start_page);
        outline_label->setObjectName(QStringLiteral("outline_label"));
        outline_label->setGeometry(QRect(MARGIN, MARGIN*4, LINEWIDTH, MARGIN*3));
        outline_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        outline_label->setWordWrap(true);
        
        consent_label = new QLabel(start_page);
        consent_label->setObjectName(QStringLiteral("consent_label"));
        consent_label->setGeometry(QRect(MARGIN, MARGIN*7, LINEWIDTH, MARGIN));
        consent_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        consent_label->setWordWrap(true);
        
        consent_btn = new QPushButton(start_page);
        consent_btn->setObjectName(QStringLiteral("consent_btn"));
        consent_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH - M, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        not_consent_btn = new QPushButton(start_page);
        not_consent_btn->setObjectName(QStringLiteral("not_consent_btn"));
        not_consent_btn->setGeometry(QRect(W/2 + M, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        stackedWidget->addWidget(start_page);

        //// goodbye page /////////////////////////////////////////////////////

        goodbye_page = new QWidget();
        goodbye_page->setObjectName(QStringLiteral("goodbye_page"));

        goodbye_label = new QLabel(goodbye_page);
        goodbye_label->setObjectName(QStringLiteral("goodbye_label"));
        goodbye_label->setGeometry(QRect(M, M, LINEWIDTH, M*4));
        goodbye_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        goodbye_label->setWordWrap(true);

        goodbye_btn = new QPushButton(goodbye_page);
        goodbye_btn->setObjectName(QStringLiteral("goodbye_btn"));
        goodbye_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        stackedWidget->addWidget(goodbye_page);

        //// task1 page ///////////////////////////////////////////////////////
        
        task1_page = new QWidget();
        task1_page->setObjectName(QStringLiteral("task1_page"));
        stackedWidget->addWidget(task1_page);

        task1_label = new QLabel(task1_page);
        task1_label->setObjectName(QStringLiteral("task1_label"));
        task1_label->setGeometry(QRect(M, M, LINEWIDTH, M*6));
        task1_label->setAlignment(Qt::AlignLeft|Qt::AlignTop);
        task1_label->setWordWrap(true);

        task1_continue_btn = new QPushButton(task1_page);
        task1_continue_btn->setObjectName(QStringLiteral("task1_continue_btn"));
        task1_continue_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));

        //// patch page ///////////////////////////////////////////////////////
        
        patch_page = new QWidget();
        patch_page->setObjectName(QStringLiteral("patch_page"));
        stackedWidget->addWidget(patch_page);

        patch_label = new QLabel(patch_page);
        patch_label->setObjectName(QStringLiteral("patch_label"));
        patch_label->setGeometry(QRect(M, M, LINEWIDTH, M*5));
        patch_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        patch_label->setWordWrap(true);

        patch_progress_bar = new QProgressBar(patch_page);
        patch_progress_bar->setGeometry(QRect(W/2 - 4*M, M*5, 8*M, M));
        patch_progress_bar->setMinimum(0);
        patch_progress_bar->setMaximum(100);
        patch_progress_bar->setValue(0);

        patch_done_label = new QLabel(patch_page);
        patch_done_label->setGeometry(QRect((W-BUTTON_WIDTH)/2, M*6, BUTTON_WIDTH, BUTTON_HEIGHT));
        patch_done_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        patch_continue_btn = new QPushButton(patch_page);
        patch_continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
        patch_continue_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        patch_continue_btn->setEnabled(false);
        patch_continue_btn->setDisabled(true);

        //// task2 page ///////////////////////////////////////////////////////
        
        task2_page = new QWidget();
        task2_page->setObjectName(QStringLiteral("task2_page"));
        stackedWidget->addWidget(task2_page);

        task2_label = new QLabel(task2_page);
        task2_label->setObjectName(QStringLiteral("task1_label"));
        task2_label->setGeometry(QRect(M, M, LINEWIDTH, M*6));
        task2_label->setAlignment(Qt::AlignLeft|Qt::AlignTop);
        task2_label->setWordWrap(true);
        task2_label->setText("You will now do some more simple tasks, similar to what you did before. You must:\n\n    1) Open a web browser.\n    2) Login to your LionMail account.\n    3) Compose and email containing:\n        a) The distance (in miles) between Central Park and Wall Street\n        b) A picture of Butler Library\n        c) Any TED talk you like (just copy and paste the URL into the video)\n    4) Send the email to hastings@cs.columbia.edu.\n    5) Click \"Continue\" below only once the above tasks are completed.");

        task2_continue_btn = new QPushButton(task2_page);
        task2_continue_btn->setObjectName(QStringLiteral("task1_continue_btn"));
        task2_continue_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        task2_continue_btn->setText("Continue");

        //// q1 page //////////////////////////////////////////////////////////

        q1_page = new QWidget();
        q1_page->setObjectName(QStringLiteral("q1_page"));
        stackedWidget->addWidget(q1_page);

        q1_label = new QLabel(q1_page);
        q1_label->setObjectName(QStringLiteral("q1_label"));
        q1_label->setGeometry(QRect(M, M, LINEWIDTH, M*5));
        q1_label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        q1_label->setWordWrap(true);
        q1_label->setText("Did you notice any differences before and after the modifications? Do not consider differences in questions asked in the web browsing task.");

        q1_button_group = new QButtonGroup(q1_page);
        q1_yes_btn = new QRadioButton(q1_page);
        q1_yes_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*5, BUTTON_WIDTH, BUTTON_HEIGHT));
        q1_yes_btn->setText("Yes");
        q1_no_btn = new QRadioButton(q1_page);
        q1_no_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*6, BUTTON_WIDTH, BUTTON_HEIGHT));
        q1_no_btn->setText("No");
        q1_button_group->addButton(q1_yes_btn);
        q1_button_group->addButton(q1_no_btn);

        q1_continue_btn = new QPushButton(q1_page);
        q1_continue_btn->setEnabled(false);
        q1_continue_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        q1_continue_btn->setText("Continue");

        //// q2 page //////////////////////////////////////////////////////////

        q2_page = new QWidget();
        q2_page->setObjectName(QStringLiteral("q2_page"));
        stackedWidget->addWidget(q2_page);
        
        q2_label = new QLabel(q2_page);
        q2_label->setObjectName(QStringLiteral("q1_label"));
        q2_label->setGeometry(QRect(M, M, LINEWIDTH, M*2));
        q2_label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        q2_label->setWordWrap(true);
        q2_label->setText("How were things different after the modifications were made? Please be descriptive.");

        q2_input = new QTextEdit(q2_page);
        q2_input->setGeometry(QRect(M, M*4, LINEWIDTH, M*3));
        
        q2_continue_btn = new QPushButton(q2_page);
        q2_continue_btn->setEnabled(false);
        q2_continue_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        q2_continue_btn->setText("Continue");

        //// q3 page //////////////////////////////////////////////////////////

        q3_page = new QWidget();
        q3_page->setObjectName(QStringLiteral("q3_page"));
        stackedWidget->addWidget(q3_page);

        q3_label = new QLabel(q3_page);
        q3_label->setObjectName(QStringLiteral("q3_label"));
        q3_label->setGeometry(QRect(M, M, LINEWIDTH, M*5));
        q3_label->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        q3_label->setWordWrap(true);
        q3_label->setText("The modifications made to the system after the first round of tasks slowed down this computer. Did you notice that this computer was running slower after the modifications were applied?");

        q3_button_group = new QButtonGroup(q3_page);
        q3_yes_btn = new QRadioButton(q3_page);
        q3_yes_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*5, BUTTON_WIDTH, BUTTON_HEIGHT));
        q3_yes_btn->setText("Yes");
        q3_no_btn = new QRadioButton(q3_page);
        q3_no_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*6, BUTTON_WIDTH, BUTTON_HEIGHT));
        q3_no_btn->setText("No");
        q3_button_group->addButton(q3_yes_btn);
        q3_button_group->addButton(q3_no_btn);

        q3_continue_btn = new QPushButton(q3_page);
        q3_continue_btn->setEnabled(false);
        q3_continue_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        q3_continue_btn->setText("Continue");

        //// q4 page //////////////////////////////////////////////////////////

        q4_page = new QWidget();
        q4_page->setObjectName(QStringLiteral("q4_page"));
        stackedWidget->addWidget(q4_page);
        
        q4_label = new QLabel(q4_page);
        q4_label->setObjectName(QStringLiteral("q1_label"));
        q4_label->setGeometry(QRect(M, M, LINEWIDTH, M*3));
        q4_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        q4_label->setWordWrap(true);
        q4_label->setText("If you had to guess by what percentage this computer was made slower in the second set of tasks, what would your guess be? For example, if a computer could normally open a web browser in 1 second and was slowed down by 50%, the slowed-down computer could open a web browser in 1.5 seconds. By what percentage do you think this computer was slowed down?.");

        q4_input = new QLineEdit(q4_page);
        q4_input->setGeometry(QRect((W-BUTTON_WIDTH)/2, M*5, BUTTON_WIDTH, BUTTON_HEIGHT));
        
        q4_continue_btn = new QPushButton(q4_page);
        q4_continue_btn->setEnabled(false);
        q4_continue_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH/2, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        q4_continue_btn->setText("Continue");

        //// wta page /////////////////////////////////////////////////////////

        wta_page = new QWidget();
        stackedWidget->addWidget(wta_page);

        wta_label = new QLabel(wta_page);
        wta_label->setObjectName(QStringLiteral("q1_label"));
        wta_label->setGeometry(QRect(M, M, LINEWIDTH, M*3));
        wta_label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        wta_label->setWordWrap(true);
        wta_label->setText("Would you be willing to accept a permanent 30% slowdown on your own computer in exchange for:");

        wta_offer = new QLabel(wta_page);
        wta_offer->setGeometry(QRect(0, M*3, W, M*2));
        wta_offer->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
        QFont font = QFont();
        font.setBold(true);
        font.setPointSize(30);
        wta_offer->setFont(font);

        wta_disclaimer_label = new QLabel(wta_page);
        wta_disclaimer_label->setGeometry(QRect(M, M*5, W-(2*M), M*3));
        wta_disclaimer_label->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
        wta_disclaimer_label->setWordWrap(true);
        wta_disclaimer_label->setText("This is for your current computer only and does not apply to any future computers you may buy.");

        wta_yes_btn = new QPushButton(wta_page);
        wta_yes_btn->setGeometry(QRect(W/2 - BUTTON_WIDTH - M, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        wta_yes_btn->setText("Yes");
        
        wta_no_btn = new QPushButton(wta_page);
        wta_no_btn->setGeometry(QRect(W/2 + M, M*8, BUTTON_WIDTH, BUTTON_HEIGHT));
        wta_no_btn->setText("No");

        ///////////////////////////////////////////////////////////////////////

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        intro_label->setText(QApplication::translate("MainWindow", "Thank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 20 minutes to complete.", Q_NULLPTR));
        consent_btn->setText(QApplication::translate("MainWindow", "I consent", Q_NULLPTR));
        outline_label->setText(QApplication::translate("MainWindow", "This experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will first have you complete some simple tasks with these modifications turned off. Later, we will turn on these modifications and ask you to complete the same set of tasks.", Q_NULLPTR));
        consent_label->setText(QApplication::translate("MainWindow", "Do you consent to participate in this study? You may exit the experiment at any point.", Q_NULLPTR));
        not_consent_btn->setText(QApplication::translate("MainWindow", "I do not consent", Q_NULLPTR));
        
        goodbye_label->setText(QApplication::translate("MainWindow", "Thank you for your participation. You may now exit this window.", Q_NULLPTR));
        goodbye_btn->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));

        task1_label->setText(QApplication::translate("MainWindow", "You will now do some simple tasks. You must:\n\n    1) Open a web browser.\n    2) Login to your LionMail account.\n    3) Compose and email containing:\n        a) The distance (in miles) between Columbia University and\n             the Empire State Building\n        b) A picture of Low Library\n        c) Any music video you like (just copy and paste the URL into the video)\n    4) Send the email to hastings@cs.columbia.edu.\n    5) Click \"Continue\" below only once the above tasks are completed.", Q_NULLPTR));
        task1_continue_btn->setText(QApplication::translate("MainWindow", "Continue", Q_NULLPTR));

        patch_label->setText(QApplication::translate("MainWindow", "We will now make some modifications to your computer. These modifications are only temporary and will end once this experiment concludes.", Q_NULLPTR));
        patch_continue_btn->setText(QApplication::translate("MainWindow", "Continue", Q_NULLPTR));

        task1_label->setText(QApplication::translate("MainWindow", "You will now do some simple tasks. You must:\n\n    1) Open a web browser.\n    2) Login to your LionMail account.\n    3) Compose and email containing:\n        a) The distance (in miles) between Columbia University and\n             the Empire State Building\n        b) A picture of Low Library\n        c) Any music video you like (just copy and paste the URL into the video)\n    4) Send the email to hastings@cs.columbia.edu.\n    5) Click \"Continue\" below only once the above tasks are completed.", Q_NULLPTR));
        task1_continue_btn->setText(QApplication::translate("MainWindow", "Continue", Q_NULLPTR));


    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
