QT       += core gui

CONFIG += c++11
CONFIG += debug_and_release


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += test.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui