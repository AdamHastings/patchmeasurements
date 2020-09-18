#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class RegistryEditPage : public QWidget
{
	Q_OBJECT

public:
	RegistryEditPage(QWidget *parent = Q_NULLPTR);
	~RegistryEditPage();

	QLabel* label;
	QPushButton* ok_btn;
	QPushButton* notok_btn;
	QLabel* done_label;

	

private:
	void setupPage();
	void makeConnections();
	void acceptOffer();
	void declineOffer();

};
