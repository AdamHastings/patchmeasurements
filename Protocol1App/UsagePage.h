#pragma once

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>

class UsagePage : public QWidget
{
	Q_OBJECT

public:
	UsagePage(QWidget *parent = Q_NULLPTR);
	~UsagePage();

	QCheckBox* gaming;
	QCheckBox* word_processing;
	QCheckBox* spreadsheets;
	QCheckBox* programming;
	QCheckBox* streaming;
	QCheckBox* video_editing;
	QCheckBox* animation;
	QCheckBox* design_tools;
	QCheckBox* web_searches;
	QCheckBox* email;
	QCheckBox* e_reading;
	QCheckBox* social_media;
	QCheckBox* video_calls;
	QCheckBox* crypto_mining;
	QCheckBox* photo_storage;
	QCheckBox* shopping;
	QCheckBox* other;

	QPushButton* continue_btn;

private:
};
