#include "TaskPage.h"
#include "Globals.h"


int TaskPage::taskCount = 1;

void TaskPage::setupWindow(QString cities, QString photo, QString video) {
    QFont titlefont = QFont();
    titlefont.setBold(true);
    titlefont.setPointSize(16);

    title = new QLabel(this);
    title->setGeometry(QRect(M, M / 2, LINEWIDTH, M));
    title->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    title->setText("Task " + QString::number(task_number));
    title->setFont(titlefont);

    header = new QLabel(this);
    header->setGeometry(QRect(M, M, LINEWIDTH, M));
    header->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    header->setWordWrap(true);
    header->setText("You will now do some simple tasks. Check off each box below as you complete the following tasks: ");

    subtask_a = new QCheckBox(this);
    subtask_a->setGeometry(QRect(M, M*2, LINEWIDTH, M));
    subtask_a->setText("Open up Microsoft Word. Create a new document titled \"Task " + QString::number(task_number) + "\".");

    subtask_b = new QCheckBox(this);
    subtask_b->setGeometry(QRect(M, M*3, LINEWIDTH, M));
    subtask_b->setText("Open Google Maps in a web browser. Find how long it would take (in hours) to drive " + cities + ". Write down this time in the Word document.");
    subtask_b->setEnabled(false);

    subtask_c = new QCheckBox(this);
    subtask_c->setGeometry(QRect(M, M * 4, LINEWIDTH, M));
    subtask_c->setText("Open any search engine in another tab. Find a picture of " + photo + ".\nCopy and paste this picture into the Word document.");
    subtask_c->setEnabled(false);

    subtask_d = new QCheckBox(this);
    subtask_d->setGeometry(QRect(M, M * 5, LINEWIDTH, M));
    subtask_d->setText("Open YouTube in another tab. Find a video of a live performance of " + video + ". Copy and paste the video's URL into the Word document.");
    subtask_d->setEnabled(false);

    subtask_e = new QCheckBox(this);
    subtask_e->setGeometry(QRect(M, M * 6, LINEWIDTH, M));
    subtask_e->setText("Save the Word document as a PDF (click on File > Save As > This PC, and then change \nthe document type from .docx to .pdf).");
    subtask_e->setEnabled(false);

    subtask_f = new QCheckBox(this);
    subtask_f->setGeometry(QRect(M, M * 7, LINEWIDTH, M));
    subtask_f->setText("Open your email. Compose a new email titled \"Task " + QString::number(task_number) + "\".\nAttach the saved PDF to the email and send to hastings-experiment@cs.columbia.edu.");
    subtask_f->setEnabled(false);

    subtask_g = new QCheckBox(this);
    subtask_g->setGeometry(QRect(M, M * 8, LINEWIDTH, M));
    subtask_g->setText("Close your email and web browser. Close Microsoft Word and delete\nthe \"Task " + QString::number(task_number) + "\" document and PDF from your computer.");
    subtask_g->setEnabled(false);

    continue_btn = new QPushButton(this);
    continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
    continue_btn->setText("Continue");
#if QT_NO_DEBUG
    continue_btn->setEnabled(false);
#endif
}

void TaskPage::makeConnections() {
    connect(this->subtask_a, &QPushButton::clicked, this->subtask_a, &QCheckBox::setDisabled);
    connect(this->subtask_b, &QPushButton::clicked, this->subtask_b, &QCheckBox::setDisabled);
    connect(this->subtask_c, &QPushButton::clicked, this->subtask_c, &QCheckBox::setDisabled);
    connect(this->subtask_d, &QPushButton::clicked, this->subtask_d, &QCheckBox::setDisabled);
    connect(this->subtask_e, &QPushButton::clicked, this->subtask_e, &QCheckBox::setDisabled);
    connect(this->subtask_f, &QPushButton::clicked, this->subtask_f, &QCheckBox::setDisabled);
    connect(this->subtask_g, &QPushButton::clicked, this->subtask_g, &QCheckBox::setDisabled);
    
    connect(this->subtask_a, &QPushButton::clicked, this->subtask_b, &QCheckBox::setEnabled);
    connect(this->subtask_b, &QPushButton::clicked, this->subtask_c, &QCheckBox::setEnabled);
    connect(this->subtask_c, &QPushButton::clicked, this->subtask_d, &QCheckBox::setEnabled);
    connect(this->subtask_d, &QPushButton::clicked, this->subtask_e, &QCheckBox::setEnabled);
    connect(this->subtask_e, &QPushButton::clicked, this->subtask_f, &QCheckBox::setEnabled);
    connect(this->subtask_f, &QPushButton::clicked, this->subtask_g, &QCheckBox::setEnabled);
    connect(this->subtask_g, &QPushButton::clicked, this->continue_btn, &QCheckBox::setEnabled);
}

TaskPage::TaskPage(QString cities, QString photo, QString video, QWidget *parent)
	: QWidget(parent)
{
    task_number = taskCount;
    setupWindow(cities, photo, video);
    makeConnections();
    taskCount++;
}

TaskPage::~TaskPage()
{
}
