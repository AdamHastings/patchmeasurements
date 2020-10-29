#include "UsagePage.h"
#include "Globals.h"

UsagePage::UsagePage(QWidget *parent)
	: QWidget(parent)
{
	gaming = new QCheckBox(this);
	gaming->setText("Gaming");
	gaming->setGeometry(M, M, 4*M, BUTTON_HEIGHT);

	word_processing = new QCheckBox(this);
	word_processing->setText("Word Processing (including Microsoft Word and Google Docs)");
	word_processing->setGeometry(M, M+BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	spreadsheets = new QCheckBox(this);
	spreadsheets->setText("Spreadsheets");
	spreadsheets->setGeometry(M, M + 2 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	programming = new QCheckBox(this);
	programming->setText("Programming/coding");
	programming->setGeometry(M, M + 3 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	streaming = new QCheckBox(this);
	streaming->setText("Streaming (audio or video)");
	streaming->setGeometry(M, M + 4 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	video_editing = new QCheckBox(this);
	video_editing->setText("Video editing");
	video_editing->setGeometry(M, M + 5 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	animation = new QCheckBox(this);
	animation->setText("Computer Animation");
	animation->setGeometry(M, M + 6 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	design_tools = new QCheckBox(this);
	design_tools->setText("Design tools (e.g. Photoshop, Illustrator, InDesign)");
	design_tools->setGeometry(M, M + 7 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	web_searches = new QCheckBox(this);
	web_searches->setText("Web searches");
	web_searches->setGeometry(5 * M, M + 0 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	email = new QCheckBox(this);
	email->setText("Email");
	email->setGeometry(5 * M, M + 1 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	e_reading = new QCheckBox(this);
	e_reading->setText("Reading");
	e_reading->setGeometry(5 * M, M + 2 * BUTTON_HEIGHT, 4 * M, BUTTON_HEIGHT);

	social_media = new QCheckBox(this);
	social_media->setText("Social media");
	social_media->setGeometry(5 * M, M + 3 * BUTTON_HEIGHT, 4 * M, BUTTON_HEIGHT);

	video_calls = new QCheckBox(this);
	video_calls->setText("Video calling (including Zoom, Skype, FaceTime, etc.)");
	video_calls->setGeometry(5 * M, M + 4 * BUTTON_HEIGHT, 4 * M, BUTTON_HEIGHT);

	crypto_mining = new QCheckBox(this);
	crypto_mining->setText("Cryptocurrency mining");
	crypto_mining->setGeometry(5 * M, M + 5 * BUTTON_HEIGHT, 4 * M, BUTTON_HEIGHT);

	photo_storage = new QCheckBox(this);
	photo_storage->setText("Photo or video storage");
	photo_storage->setGeometry(5 * M, M + 6 * BUTTON_HEIGHT, 4 * M, BUTTON_HEIGHT);

	shopping = new QCheckBox(this);
	shopping->setText("Shopping");
	shopping->setGeometry(5 * M, M + 7 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	other = new QCheckBox(this);
	other->setText("Other (please specify)");
	other->setGeometry(M, M + 8 * BUTTON_HEIGHT, 4*M, BUTTON_HEIGHT);

	continue_btn = new QPushButton(this);
	continue_btn->setText("Continue");
	continue_btn->setGeometry(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT);

}

UsagePage::~UsagePage()
{
}
