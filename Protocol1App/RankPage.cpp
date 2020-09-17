#include "RankPage.h"
#include "Globals.h"
#include <QSize>
#include <vector>
#include <QLabel>
#include <QPixMap>
#include <QHBoxLayout>

void RankPage::enableContinue(QListWidgetItem* item) {
	this->continue_btn->setEnabled(true);
}

RankPage::RankPage(QWidget* parent)
	: QWidget(parent)

{

	// TODO making participants rank informs them that there were differences in speeds....

	QLabel* label = new QLabel("The speed of your computer may have been modified during the previous three tasks. To the best of your ability, please rank how fast you think your computer was running during each of the three tasks. Grab and drop the boxes below to rank them fastest to slowest, top to bottom. If you didn't notice a difference in speed between any two given tasks, it is OK to arbitrarily pick one over the other.", this);
	label->setAlignment(Qt::AlignVCenter | Qt::AlignJustify);
	label->setWordWrap(true);
	label->setGeometry(QRect(M, M/2, LINEWIDTH, 2 * M));



	listWidget = new QListWidget(this);
	int num_tasks = 3;
	for (int i = 0; i < num_tasks; i++) {
		QString title = QString("Task %1").arg(i+1);
		QListWidgetItem* item = new QListWidgetItem(title);
		item->setData(Qt::SizeHintRole, QSize(M, M));
		item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
		listWidget->addItem(item);
	}
	listWidget->setDragDropMode(QAbstractItemView::InternalMove);
	listWidget->setDragEnabled(true);
	listWidget->setAcceptDrops(true);
	listWidget->setDropIndicatorShown(true);
	listWidget->viewport()->setAcceptDrops(true);
	listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	listWidget->setGeometry(QRect(W / 2 - 4 * M, 3 * M, 4 * M, 4 * M));
	listWidget->setCurrentRow(0);

	QLabel* fastest = new QLabel("(Fastest)", this);
	fastest->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	fastest->setGeometry(QRect(W/2+M/4, 3 * M, 2*M, M));

	/*QPixmap* fast_pmap = new QPixmap("car.png");
	*fast_pmap = fast_pmap->scaledToHeight(M);
	QLabel* fast_pic = new QLabel(this);
	fast_pic->setPixmap(*fast_pmap);
	fast_pic->setGeometry(QRect(W / 2 + M / 4 + M, 3 * M, M, M));*/

	/*QHBoxLayout* fastlayout = new QHBoxLayout(this);
	fastlayout->addWidget(fastest);
	fastlayout->addWidget(fast_pic);
	fastlayout->setGeometry(QRect(M, 2 * M, LINEWIDTH, M));*/


	QLabel* slowest = new QLabel("(Slowest)", this);
	slowest->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	slowest->setGeometry(QRect(W / 2 + M / 4, 5 * M, 2* M, M));

	

	continue_btn = new QPushButton(this);
	continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 8, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");

#if QT_NO_DEBUG
	continue_btn->setEnabled(false);
#endif

	connect(listWidget, &QListWidget::itemClicked, this, &RankPage::enableContinue);
}

RankPage::~RankPage()
{
}
