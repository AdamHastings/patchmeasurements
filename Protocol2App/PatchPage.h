#pragma once

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

class PatchPage : public QWidget
{
    Q_OBJECT

public:
    PatchPage(QWidget* parent = Q_NULLPTR);
    ~PatchPage();

    QLabel* label;
    QLabel* done_label;
    QProgressBar* progress_bar;
    QPushButton* continue_btn;

public:
    void fillBar();
    void slowFillBar();
    void fillFirstHalf();
    void fillSecondHalf();
    void fillFirstThird();
    void fillSecondThird();
    void fillThirdThird();
};
