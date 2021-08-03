#pragma once

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class UsagePage : public QWidget
{
	Q_OBJECT

public:
	UsagePage(QWidget* parent = Q_NULLPTR);
	~UsagePage();

	static QCheckBox* gaming;
	static QCheckBox* word_processing;
	static QCheckBox* spreadsheets;
	static QCheckBox* programming;
	static QCheckBox* streaming;
	static QCheckBox* video_editing;
	static QCheckBox* animation;
	static QCheckBox* design_tools;
	static QCheckBox* web_searches;
	static QCheckBox* email;
	static QCheckBox* e_reading;
	static QCheckBox* social_media;
	static QCheckBox* video_calls;
	static QCheckBox* crypto_mining;
	static QCheckBox* photo_storage;
	static QCheckBox* shopping;
	static QCheckBox* other;
	static QLineEdit* input;

	QPushButton* continue_btn;

private:
	QLabel* label;
	void checkIfContinue();
	void handleOther();
};


class SellingPointsPage : public QWidget
{
	Q_OBJECT

public:
	SellingPointsPage(QWidget* parent = Q_NULLPTR);

	static QCheckBox* performance;
	static QCheckBox* looks;
	static QCheckBox* price;
	static QCheckBox* security;
	static QCheckBox* os;
	static QCheckBox* apps;
	static QCheckBox* other;
	static QLineEdit* input;

	QPushButton* continue_btn;

private:
	QLabel* label;
	void checkIfContinue();
	void handleOther();
};
