#pragma once

#include <QWidget>
#include "ui_ComparePage.h"

class ComparePage : public QWidget
{
	Q_OBJECT

public:
	ComparePage(QWidget *parent = Q_NULLPTR);
	~ComparePage();

private:
	Ui::ComparePage ui;
};
