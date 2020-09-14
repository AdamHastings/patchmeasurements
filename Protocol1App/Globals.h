#pragma once
#include <QRect>
#include <algorithm>
#include <QApplication>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QDesktopWidget>

const QRect r = QApplication::desktop()->screenGeometry();

const int H = std::min(r.height() / 2, r.width() / 2);
const int W = std::max(r.height() / 2, r.width() / 2);

const int MARGIN = H / 10;
const int M = MARGIN;
const int LINEWIDTH = W - (2 * MARGIN);

const int BUTTON_WIDTH = W / 4;
const int BUTTON_HEIGHT = H / 16;

