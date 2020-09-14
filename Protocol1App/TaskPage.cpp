#include "TaskPage.h"
#include "Globals.h"


void TaskPage::setupWindow() {
    QFont titlefont = QFont();
    titlefont.setBold(true);
    titlefont.setPointSize(16);

    title = new QLabel(this);
    title->setGeometry(QRect(M, M / 2, LINEWIDTH, M));
    title->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    title->setText("Task 1");
    title->setFont(titlefont);

    header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M));
    header->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    header->setWordWrap(true);
    header->setText("You will now do some simple tasks. Check off each box below as you complete the following tasks: ");

    subtask_a = new QCheckBox(this);
    subtask_a->setGeometry(QRect(M, BUTTON_HEIGHT * 4, LINEWIDTH, BUTTON_HEIGHT));

    subtask_b = new QCheckBox(this);
    subtask_b->setGeometry(QRect(M, BUTTON_HEIGHT * 5, LINEWIDTH, BUTTON_HEIGHT));
    //subtask_b->setText("Open Google Maps in a new tab. Find the distance (in miles) between New York City and Los Angeles.");
    subtask_b->setEnabled(false);

    subtask_c = new QCheckBox(this);
    subtask_c->setGeometry(QRect(M, BUTTON_HEIGHT * 6, LINEWIDTH, BUTTON_HEIGHT));
    subtask_c->setText("Write down this distance in the Google Doc.");
    subtask_c->setEnabled(false);

    subtask_d = new QCheckBox(this);
    subtask_d->setGeometry(QRect(M, BUTTON_HEIGHT * 7, LINEWIDTH, BUTTON_HEIGHT));
    //subtask_d->setText("Open any search engine in another tab and find any picture of Low Library.");
    subtask_d->setEnabled(false);

    subtask_e = new QCheckBox(this);
    subtask_e->setGeometry(QRect(M, BUTTON_HEIGHT * 8, LINEWIDTH, BUTTON_HEIGHT));
    subtask_e->setText("Copy and paste this picture into the Google Doc.");
    subtask_e->setEnabled(false);

    subtask_f = new QCheckBox(this);
    subtask_f->setGeometry(QRect(M, BUTTON_HEIGHT * 9, LINEWIDTH, BUTTON_HEIGHT));
    //subtask_f->setText("Open YouTube in another tab. Find a video of jazz trumpeter Miles Davis performing the song \"So What\" live.");
    subtask_f->setEnabled(false);

    subtask_g = new QCheckBox(this);
    subtask_g->setGeometry(QRect(M, BUTTON_HEIGHT * 10, LINEWIDTH, BUTTON_HEIGHT));
    subtask_g->setText("Copy and paste this video's URL into the Google Doc.");
    subtask_g->setEnabled(false);

    subtask_h = new QCheckBox(this);
    subtask_h->setGeometry(QRect(M, BUTTON_HEIGHT * 11, LINEWIDTH, BUTTON_HEIGHT));
    subtask_h->setText("Download the Google Doc as a PDF (click on File > Download > PDF Document ).");
    subtask_h->setEnabled(false);

    subtask_i = new QCheckBox(this);
    subtask_i->setGeometry(QRect(M, BUTTON_HEIGHT * 12, LINEWIDTH, BUTTON_HEIGHT));
    subtask_i->setText("Open LionMail in a new tab. Compose a new email titled \"<your uni>-subtask_\" (where <your uni> is your UNI).\n Attach the downloaded PDF to the email and send to tasks-test-2020@cs.columbia.edu.");
    subtask_i->setEnabled(false);

    subtask_j = new QCheckBox(this);
    subtask_j->setGeometry(QRect(M, BUTTON_HEIGHT * 13, LINEWIDTH, BUTTON_HEIGHT));
    subtask_j->setText("Close all tabs and delete the previously downloaded PDF from your computer.");
    subtask_j->setEnabled(false);

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
    continue_btn->setEnabled(false);
}

void TaskPage::makeConnections() {
    connect(this->subtask_a, &QPushButton::clicked, this->subtask_b, &QCheckBox::setEnabled);
    connect(this->subtask_b, &QPushButton::clicked, this->subtask_c, &QCheckBox::setEnabled);
    connect(this->subtask_c, &QPushButton::clicked, this->subtask_d, &QCheckBox::setEnabled);
    connect(this->subtask_d, &QPushButton::clicked, this->subtask_e, &QCheckBox::setEnabled);
    connect(this->subtask_e, &QPushButton::clicked, this->subtask_f, &QCheckBox::setEnabled);
    connect(this->subtask_f, &QPushButton::clicked, this->subtask_g, &QCheckBox::setEnabled);
    connect(this->subtask_g, &QPushButton::clicked, this->subtask_h, &QCheckBox::setEnabled);
    connect(this->subtask_h, &QPushButton::clicked, this->subtask_i, &QCheckBox::setEnabled);
    connect(this->subtask_i, &QPushButton::clicked, this->subtask_j, &QCheckBox::setEnabled);
    connect(this->subtask_j, &QPushButton::clicked, this->continue_btn, &QPushButton::setEnabled);
    
    connect(this->subtask_a, &QPushButton::clicked, this->subtask_a, &QCheckBox::setDisabled);
    connect(this->subtask_b, &QPushButton::clicked, this->subtask_b, &QCheckBox::setDisabled);
    connect(this->subtask_c, &QPushButton::clicked, this->subtask_c, &QCheckBox::setDisabled);
    connect(this->subtask_d, &QPushButton::clicked, this->subtask_d, &QCheckBox::setDisabled);
    connect(this->subtask_e, &QPushButton::clicked, this->subtask_e, &QCheckBox::setDisabled);
    connect(this->subtask_f, &QPushButton::clicked, this->subtask_f, &QCheckBox::setDisabled);
    connect(this->subtask_g, &QPushButton::clicked, this->subtask_g, &QCheckBox::setDisabled);
    connect(this->subtask_h, &QPushButton::clicked, this->subtask_h, &QCheckBox::setDisabled);
    connect(this->subtask_i, &QPushButton::clicked, this->subtask_i, &QCheckBox::setDisabled);
    connect(this->subtask_j, &QPushButton::clicked, this->subtask_j, &QCheckBox::setDisabled); 
}

TaskPage::TaskPage(QWidget *parent)
	: QWidget(parent)
{
    setupWindow();
    makeConnections();
}

void TaskPage::setCities(QString s1, QString s2) {
    QString text = "Open Google Maps in a new tab. Find the distance (in miles) between " + s1 + " and " + s2 + ".";
    subtask_b->setText(text);
}

void TaskPage::setPhoto(QString s) {
    QString text = "Open any search engine in another tab and find any picture of " + s + ".";
    subtask_d->setText(text);
}

void TaskPage::setVideo(QString s) {
    QString text = "Open YouTube in another tab. Find a video of a live performance of the classical music piece " + s + ".";
    subtask_f->setText(text);
}

void TaskPage::setTaskNum(int n) {
    QString num = QString::number(n);
    subtask_a->setText("Open up a web browser. Login to your LionMail account. Create a new Google Doc titled \"Task " + num + "\".");
    subtask_i->setText("Open LionMail in a new tab. Compose a new email titled \"<your uni>-" + num + "\" (where <your uni> is your UNI).\n Attach the downloaded PDF to the email and send to tasks-experiment-2020@cs.columbia.edu.");
}

TaskPage::~TaskPage()
{
}
