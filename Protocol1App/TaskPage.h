#pragma once

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QString>
#include <QProcess>
#include <vector>

class TaskPage : public QWidget
{
	Q_OBJECT

public:
	TaskPage(QString cities, QString photo, QString video, QWidget* parent = Q_NULLPTR);
	~TaskPage();

    int task_number;
    static int taskCount;
    QString cpu_utilizations = "";
    QString ram_utilizations = "";
    void logCPUUtilization();
    void logRAMUtilization();
    void resetPage(QString uni, int tasknum);
    

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

private:

    void setupWindow(QString cities, QString photo, QString video);
    void makeConnections();

    void handle_a();
    void handle_b();
    void handle_c();
    void handle_d();
    void handle_e();
    void handle_f();
    void handle_g();

    QProcess cpuProc;
    QProcess ramProc;
};
