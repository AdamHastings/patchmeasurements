# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'color-switch-tutorial.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setMinimumSize(QtCore.QSize(800, 600))
        MainWindow.setMaximumSize(QtCore.QSize(800, 600))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.stackedWidget = QtWidgets.QStackedWidget(self.centralwidget)
        self.stackedWidget.setGeometry(QtCore.QRect(40, 30, 711, 441))
        self.stackedWidget.setObjectName("stackedWidget")
        self.Home = QtWidgets.QWidget()
        self.Home.setObjectName("Home")
        self.label = QtWidgets.QLabel(self.Home)
        self.label.setGeometry(QtCore.QRect(220, 170, 191, 121))
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setWordWrap(True)
        self.label.setObjectName("label")
        self.stackedWidget.addWidget(self.Home)
        self.Yellow_page = QtWidgets.QWidget()
        self.Yellow_page.setStyleSheet("background-color:yellow")
        self.Yellow_page.setObjectName("Yellow_page")
        self.stackedWidget.addWidget(self.Yellow_page)
        self.Blue_page = QtWidgets.QWidget()
        self.Blue_page.setStyleSheet("background-color:blue")
        self.Blue_page.setObjectName("Blue_page")
        self.stackedWidget.addWidget(self.Blue_page)
        self.Red_page = QtWidgets.QWidget()
        self.Red_page.setStyleSheet("background-color:red")
        self.Red_page.setObjectName("Red_page")
        self.stackedWidget.addWidget(self.Red_page)
        self.blu_btn = QtWidgets.QPushButton(self.centralwidget)
        self.blu_btn.setGeometry(QtCore.QRect(120, 510, 89, 25))
        self.blu_btn.setObjectName("blu_btn")
        self.red_btn = QtWidgets.QPushButton(self.centralwidget)
        self.red_btn.setGeometry(QtCore.QRect(360, 500, 89, 25))
        self.red_btn.setObjectName("red_btn")
        self.ylw_btn = QtWidgets.QPushButton(self.centralwidget)
        self.ylw_btn.setGeometry(QtCore.QRect(600, 500, 89, 25))
        self.ylw_btn.setStyleSheet("background")
        self.ylw_btn.setObjectName("ylw_btn")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.stackedWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Please click the desired button below to get the color you want"))
        self.blu_btn.setText(_translate("MainWindow", "Blue"))
        self.red_btn.setText(_translate("MainWindow", "Red"))
        self.ylw_btn.setText(_translate("MainWindow", "Yellow"))

