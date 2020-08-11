QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = colors
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += color-switch-tutorial.ui