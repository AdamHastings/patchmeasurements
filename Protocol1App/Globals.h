#pragma once
#include <QRect>
#include <QtWidgets/QApplication>
#include <algorithm>
#include <QDesktopWidget>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>


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


//inline const QRect rec = QApplication::desktop()->screenGeometry();
//extern int H;
//extern int W;
//extern int MARGIN;
//extern int M;
//extern int LINEWIDTH;
//extern int BUTTON_WIDTH;
//extern int BUTTON_HEIGHT;
//
//inline int H;
//inline int W;
//inline int MARGIN;
//inline int M;
//inline int LINEWIDTH;
//inline int BUTTON_WIDTH;
//inline int BUTTON_HEIGHT;
//
//inline void globals_init(QRect rec) {
//	H = std::min(rec.height() / 2, rec.width() / 2);
//	W = std::max(rec.height() / 2, rec.width() / 2);
//
//	MARGIN = H / 10;
//	M = MARGIN;
//	LINEWIDTH = W - (2 * MARGIN);
//
//	BUTTON_WIDTH = W / 4;
//	BUTTON_HEIGHT = H / 16;
//}

//#define H (std::min(rec.height() / 2, rec.width() / 2))
//#define W (std::max(rec.height() / 2, rec.width() / 2))
//#define MARGIN ( H / 10 )
//#define M (MARGIN)
//#define LINEWIDTH (W - (2 * MARGIN));
//#define BUTTON_WIDTH (W / 4)
//#define BUTTON_HEIGHT (H / 16)

//inline int getHeight() {
//	QRect rec = QApplication::desktop()->screenGeometry();
//	return std::min(rec.height() / 2, rec.width() / 2);
//}
//
//inline int getWidth() {
//	QRect rec = QApplication::desktop()->screenGeometry();
//	return std::max(rec.height() / 2, rec.width() / 2);
//}


//inline const int H = std::min(rec.height() / 2, rec.width() / 2);
//inline const int W = std::max(rec.height() / 2, rec.width() / 2);
//inline int H = 2000;
//inline int W = 4000;
//inline const QScreen* screen = QGuiApplication::primaryScreen();		   
//inline const QRect  screenGeometry = screen->geometry();
//inline const int H = screenGeometry.height();
//inline const int W = screenGeometry.width();
//
//inline const int H = getHeight();
//inline const int W = getWidth();
//
//inline const int MARGIN = H / 10;
//inline const int M = MARGIN;
//inline const int LINEWIDTH = W - (2 * MARGIN);
//inline const int BUTTON_WIDTH = W / 4;
//inline const int BUTTON_HEIGHT = H / 16;

//void globals_init(QRect rec)