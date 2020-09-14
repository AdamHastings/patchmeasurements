#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class StartPage : public QWidget
{
	Q_OBJECT

public:
	StartPage(QWidget *parent = Q_NULLPTR);
	~StartPage();

	QLabel* intro_label;
	QLabel* outline_label;
	QLabel* consent_label;
	QPushButton* consent_btn;
	QPushButton* not_consent_btn;
};
