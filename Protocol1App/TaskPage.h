#pragma once

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QString>

class TaskPage : public QWidget
{
	Q_OBJECT

public:
	TaskPage(QWidget *parent = Q_NULLPTR);
	~TaskPage();

    int task_number;
    QString city1;
    QString city2;
    QString photo;
    QString video;

    void setTaskNum(int n);
    void setCities(QString s1, QString cs);
    void setPhoto(QString s);
    void setVideo(QString s);

    QLabel* title;
    QLabel* header;
    QCheckBox* subtask_a;
    QCheckBox* subtask_b;
    QCheckBox* subtask_c;
    QCheckBox* subtask_d;
    QCheckBox* subtask_e;
    QCheckBox* subtask_f;
    QCheckBox* subtask_g;
    QCheckBox* subtask_h;
    QCheckBox* subtask_i;
    QCheckBox* subtask_j;
    QPushButton* continue_btn;
};
