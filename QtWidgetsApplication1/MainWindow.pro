QT       += core gui network

CONFIG += c++11
CONFIG += debug_and_release


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp \
            MainWindow.cpp \
            dropbox.cpp
            

HEADERS  += MainWindow.h \
            Ui_MainWindow.h \
            dropbox.h

