#include "RankPage.h"
#include "Globals.h"
#include <QSize>
#include <vector>
#include <QLabel>

void RankPage::enableContinue() {
	this->continue_btn->setEnabled(true);
}

RankPage::RankPage(QWidget *parent)
	: QWidget(parent)
{
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
	listWidget->setGeometry(QRect(W / 2 - 4 * M, 3 * M, 8 * M, 4 * M));
	//listWidget->setCurrentRow(0);

	QLabel* fastest = new QLabel("Fastest", this);
	fastest->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	fastest->setGeometry(QRect(M, 2 * M, LINEWIDTH, M));

	QLabel* slowest = new QLabel("Slowest", this);
	slowest->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	slowest->setGeometry(QRect(M, 7 * M, LINEWIDTH, M));


	continue_btn = new QPushButton(this);
	continue_btn->setObjectName(QStringLiteral("patch_continue_btn"));
	continue_btn->setGeometry(QRect(W / 2 - BUTTON_WIDTH / 2, M * 9, BUTTON_WIDTH, BUTTON_HEIGHT));
	continue_btn->setText("Continue");

#if QT_NO_DEBUG
	continue_btn->setEnabled(false);
#endif

	connect(listWidget, &QListWidget::itemSelectionChanged, this, &RankPage::enableContinue);
}

RankPage::~RankPage()
{
}
