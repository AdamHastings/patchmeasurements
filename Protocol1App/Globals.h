#pragma once
#include <QRect>
#include <QtWidgets/QApplication>
#include <algorithm>
#include <QDesktopWidget>


#if !defined(CONSTANTS_LIB)
#define CONSTANTS_LIB 1

inline QRect rec = QApplication::desktop()->screenGeometry();
inline int H = std::min(rec.height() / 2, rec.width() / 2);
inline int W = std::max(rec.height() / 2, rec.width() / 2);
inline int MARGIN = H / 10;
inline int M = MARGIN;
inline int LINEWIDTH = W - (2 * MARGIN);
inline int BUTTON_WIDTH = W / 4;
inline int BUTTON_HEIGHT = H / 16;


#endif