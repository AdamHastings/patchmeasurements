# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainWindow.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):

        ### Globals ###########################################################

        HEIGHT = 400
        WIDTH  = 600 

        H_MARGIN = 40
        V_MARGIN = 40

        BUTTON_WIDTH  = 140
        BUTTON_HEIGHT = 25

        ### Main setup ########################################################

        MainWindow.setObjectName("MainWindow")
        MainWindow.setMinimumSize(QtCore.QSize(WIDTH, HEIGHT))
        MainWindow.setMaximumSize(QtCore.QSize(WIDTH, HEIGHT))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setMinimumSize(QtCore.QSize(WIDTH, HEIGHT))
        self.centralwidget.setMaximumSize(QtCore.QSize(WIDTH, HEIGHT))
        self.centralwidget.setObjectName("centralwidget")
        self.stackedWidget = QtWidgets.QStackedWidget(self.centralwidget)
        self.stackedWidget.setGeometry(QtCore.QRect(0, 0, WIDTH, HEIGHT))
        self.stackedWidget.setMinimumSize(QtCore.QSize(WIDTH, HEIGHT))
        self.stackedWidget.setMaximumSize(QtCore.QSize(WIDTH, HEIGHT))
        self.stackedWidget.setObjectName("stackedWidget")
        
        ### start page ########################################################
        
        self.start_page = QtWidgets.QWidget()
        self.start_page.setObjectName("start_page")
        
        self.intro_label = QtWidgets.QLabel(self.start_page)
        self.intro_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 90))
        self.intro_label.setAlignment(QtCore.Qt.AlignJustify|QtCore.Qt.AlignVCenter)
        self.intro_label.setWordWrap(True)
        self.intro_label.setObjectName("intro_label")

        self.outline_label = QtWidgets.QLabel(self.start_page)
        self.outline_label.setGeometry(QtCore.QRect(H_MARGIN, 130, WIDTH-(2*H_MARGIN), 100))
        self.outline_label.setAlignment(QtCore.Qt.AlignJustify|QtCore.Qt.AlignVCenter)
        self.outline_label.setWordWrap(True)
        self.outline_label.setObjectName("outline_label")
        
        self.consent_label = QtWidgets.QLabel(self.start_page)
        self.consent_label.setGeometry(QtCore.QRect(H_MARGIN, 220, WIDTH-(2*H_MARGIN), 50))
        self.consent_label.setAlignment(QtCore.Qt.AlignJustify|QtCore.Qt.AlignVCenter)
        self.consent_label.setWordWrap(True)
        self.consent_label.setObjectName("consent_label")

        self.consent_btn = QtWidgets.QPushButton(self.start_page)
        self.consent_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH - H_MARGIN, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.consent_btn.setObjectName("consent_btn")
        
        self.not_consent_btn = QtWidgets.QPushButton(self.start_page)
        self.not_consent_btn.setGeometry(QtCore.QRect(WIDTH/2 + H_MARGIN, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.not_consent_btn.setObjectName("not_consent_btn")

        self.stackedWidget.addWidget(self.start_page)
       
        ### goodbye page ######################################################
        
        self.goodbye_page = QtWidgets.QWidget()
        self.goodbye_page.setObjectName("goodbye_page")
        self.stackedWidget.addWidget(self.goodbye_page)

        self.goodbye_label = QtWidgets.QLabel(self.goodbye_page)
        self.goodbye_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 100))
        self.goodbye_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.goodbye_label.setWordWrap(True)
        self.goodbye_label.setObjectName("goodbye_label")

        ### task1 page ########################################################

        self.task1_page = QtWidgets.QWidget()
        self.task1_page.setObjectName("task1_page")
        self.stackedWidget.addWidget(self.task1_page)

        self.task1_label = QtWidgets.QLabel(self.task1_page)
        self.task1_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 200))
        self.task1_label.setAlignment(QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.task1_label.setWordWrap(True)
        self.task1_label.setObjectName("task1_label")

        self.task1_continue_btn = QtWidgets.QPushButton(self.task1_page)
        self.task1_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.task1_continue_btn.setObjectName("task1_continue_btn")

        ### patch page ########################################################

        self.patch_page = QtWidgets.QWidget()
        self.patch_page.setObjectName("patch_page")
        self.stackedWidget.addWidget(self.patch_page)

        self.patch_label = QtWidgets.QLabel(self.patch_page)
        self.patch_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 200))
        self.patch_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.patch_label.setWordWrap(True)
        self.patch_label.setObjectName("patch_label")

        self.patch_continue_btn = QtWidgets.QPushButton(self.patch_page)
        self.patch_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.patch_continue_btn.setObjectName("patch_continue_btn")

        ### task2 page ########################################################
        
        self.task2_page = QtWidgets.QWidget()
        self.task2_page.setObjectName("task2_page")
        self.stackedWidget.addWidget(self.task2_page)

        self.task2_label = QtWidgets.QLabel(self.task2_page)
        self.task2_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 200))
        self.task2_label.setAlignment(QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.task2_label.setWordWrap(True)
        self.task2_label.setObjectName("task2_label")

        self.task2_continue_btn = QtWidgets.QPushButton(self.task2_page)
        self.task2_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.task2_continue_btn.setObjectName("task2_continue_btn")

        ### q1 page ###########################################################

        self.q1_page = QtWidgets.QWidget()
        self.q1_page.setObjectName("q1_page")
        self.stackedWidget.addWidget(self.q1_page)

        self.q1_label = QtWidgets.QLabel(self.q1_page)
        self.q1_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 200))
        self.q1_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.q1_label.setWordWrap(True)
        self.q1_label.setObjectName("q1_label")

        self.q1_button_group = QtWidgets.QButtonGroup(self.q1_page)
        self.q1_yes_btn = QtWidgets.QRadioButton(self.q1_page)
        self.q1_yes_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 220, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q1_no_btn = QtWidgets.QRadioButton(self.q1_page)
        self.q1_no_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 220 + BUTTON_HEIGHT + 10, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q1_button_group.addButton(self.q1_yes_btn)
        self.q1_button_group.addButton(self.q1_no_btn)

        self.q1_continue_btn = QtWidgets.QPushButton(self.q1_page)
        self.q1_continue_btn.setDisabled(True)
        self.q1_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q1_continue_btn.setObjectName("q1_continue_btn")

        ### q2 page ###########################################################

        self.q2_page = QtWidgets.QWidget()
        self.q2_page.setObjectName("q2_page")
        self.stackedWidget.addWidget(self.q2_page)

        self.q2_label = QtWidgets.QLabel(self.q2_page)
        self.q2_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 100))
        self.q2_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.q2_label.setWordWrap(True)
        self.q2_label.setObjectName("q2_label")

        self.q2_input = QtWidgets.QTextEdit(self.q2_page)
        self.q2_input.setGeometry(QtCore.QRect(H_MARGIN, 120, WIDTH-(2*H_MARGIN), 140))
        self.q2_input.setObjectName("q2_input")

        self.q2_continue_btn = QtWidgets.QPushButton(self.q2_page)
        self.q2_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q2_continue_btn.setObjectName("q2_continue_btn")

        ### q3 page ###########################################################

        self.q3_page = QtWidgets.QWidget()
        self.q3_page.setObjectName("q3_page")
        self.stackedWidget.addWidget(self.q3_page)

        self.q3_label = QtWidgets.QLabel(self.q3_page)
        self.q3_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 200))
        self.q3_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.q3_label.setWordWrap(True)
        self.q3_label.setObjectName("q3_label")

        self.q3_button_group = QtWidgets.QButtonGroup(self.q3_page)
        self.q3_yes_btn = QtWidgets.QRadioButton(self.q3_page)
        self.q3_yes_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 220, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q3_no_btn = QtWidgets.QRadioButton(self.q3_page)
        self.q3_no_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 220 + BUTTON_HEIGHT + 10, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q3_button_group.addButton(self.q3_yes_btn)
        self.q3_button_group.addButton(self.q3_no_btn)

        self.q3_continue_btn = QtWidgets.QPushButton(self.q3_page)
        self.q3_continue_btn.setDisabled(True)
        self.q3_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q3_continue_btn.setObjectName("q3_continue_btn")

        ### q4 page ###########################################################

        self.q4_page = QtWidgets.QWidget()
        self.q4_page.setObjectName("q4_page")
        self.stackedWidget.addWidget(self.q4_page)

        self.q4_label = QtWidgets.QLabel(self.q4_page)
        self.q4_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 100))
        self.q4_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.q4_label.setWordWrap(True)
        self.q4_label.setObjectName("q4_label")

        self.q4_input = QtWidgets.QLineEdit(self.q4_page)
        self.q4_input.setGeometry(QtCore.QRect(H_MARGIN, 180, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q4_input.setObjectName("q4_input")

        self.q4_continue_btn = QtWidgets.QPushButton(self.q4_page)
        self.q4_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        self.q4_continue_btn.setObjectName("q4_continue_btn")

        ### wta page ##########################################################

        self.wta_page = QtWidgets.QWidget()
        self.wta_page.setObjectName("wta_page")
        self.stackedWidget.addWidget(self.wta_page)

        # self.wta_button_group = QtWidgets.QButtonGroup(self.wta_page)
        # self.wta_yes_btn = QtWidgets.QRadioButton(self.wta_page)
        # self.wta_yes_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 220, BUTTON_WIDTH, BUTTON_HEIGHT))
        # self.wta_no_btn = QtWidgets.QRadioButton(self.wta_page)
        # self.wta_no_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 220 + BUTTON_HEIGHT + 10, BUTTON_WIDTH, BUTTON_HEIGHT))
        # self.wta_button_group.addButton(self.wta_yes_btn)
        # self.wta_button_group.addButton(self.wta_no_btn)

        # self.wta_continue_btn = QtWidgets.QPushButton(self.wta_page)
        # self.wta_continue_btn.setDisabled(True)
        # self.wta_continue_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH/2, 330, BUTTON_WIDTH, BUTTON_HEIGHT))
        # self.wta_continue_btn.setObjectName("wta_continue_btn")

        self.wta_label = QtWidgets.QLabel(self.wta_page)
        self.wta_label.setGeometry(QtCore.QRect(H_MARGIN, V_MARGIN, WIDTH-(2*H_MARGIN), 80))
        self.wta_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.wta_label.setWordWrap(True)

        self.wta_offer = QtWidgets.QLabel(self.wta_page)
        self.wta_offer.setGeometry(QtCore.QRect(WIDTH/2-H_MARGIN, 120, 2*H_MARGIN, 50))
        self.wta_offer.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.font = QtGui.QFont()
        self.font.setBold(True)
        self.font.setPointSize(30)
        self.wta_offer.setFont(self.font)

        self.wta_disclaimer_label = QtWidgets.QLabel(self.wta_page)
        self.wta_disclaimer_label.setGeometry(QtCore.QRect(H_MARGIN, 180, WIDTH-(2*H_MARGIN), 100))
        self.wta_disclaimer_label.setAlignment(QtCore.Qt.AlignHCenter|QtCore.Qt.AlignVCenter)
        self.wta_disclaimer_label.setWordWrap(True)

        self.wta_yes_btn = QtWidgets.QPushButton(self.wta_page)
        self.wta_yes_btn.setGeometry(QtCore.QRect(WIDTH/2 - BUTTON_WIDTH - H_MARGIN, 330, BUTTON_WIDTH, BUTTON_HEIGHT))        
        
        self.wta_no_btn = QtWidgets.QPushButton(self.wta_page)
        self.wta_no_btn.setGeometry(QtCore.QRect(WIDTH/2 + H_MARGIN, 330, BUTTON_WIDTH, BUTTON_HEIGHT))

        #######################################################################

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, WIDTH, 22))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.stackedWidget.setCurrentIndex(2)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.intro_label.setText(_translate("MainWindow", "Thank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 20 minutes to complete."))
        self.consent_btn.setText(_translate("MainWindow", "I consent"))
        self.outline_label.setText(_translate("MainWindow", "This experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will first have you complete some simple tasks with these modifications turned off. Later, we will turn on these modifications and ask you to complete the same set of tasks."))
        self.consent_label.setText(_translate("MainWindow", "Do you consent to participate in this study? You may exit the experiment at any point."))
        self.not_consent_btn.setText(_translate("MainWindow", "I do not consent"))
        self.goodbye_label.setText(_translate("MainWindow", "Thank you for your participation. You may now exit this window."))
        self.task1_label.setText(_translate("MainWindow", "You will now do some simple tasks. You must:\n\n    1) Open a web browser.\n    2) Login to your LionMail account.\n    3) Compose and email containing:\n        a) The distance (in miles) between Columbia University and\n             the Empire State Building\n        b) A picture of Low Library\n        c) Any music video you like (just copy and paste the URL into the video)\n    4) Send the email to hastings@cs.columbia.edu.\n    5) Click \"Continue\" below only once the above tasks are completed."))
        self.task1_continue_btn.setText(_translate("MainWindow", "Continue"))
        self.task2_label.setText(_translate("MainWindow", "You will now do some more simple tasks, similar to what you did before. You must:\n\n    1) Open a web browser.\n    2) Login to your LionMail account.\n    3) Compose and email containing:\n        a) The distance (in miles) between Central Park and Wall Street\n        b) A picture of Butler Library\n        c) Any TED talk you like (just copy and paste the URL into the video)\n    4) Send the email to hastings@cs.columbia.edu.\n    5) Click \"Continue\" below only once the above tasks are completed."))
        self.task2_continue_btn.setText(_translate("MainWindow", "Continue"))
        self.patch_continue_btn.setText(_translate("MainWindow", "Continue"))
        self.patch_label.setText(_translate("MainWindow", "We will now make some modifications to your computer. These modifications are only temporary and will end once this experiment concludes."))
        self.q1_continue_btn.setText(_translate("MainWindow", "Continue"))
        self.q2_continue_btn.setText(_translate("MainWindow", "Continue"))
        self.q3_continue_btn.setText(_translate("MainWindow", "Continue"))
        self.q4_continue_btn.setText(_translate("MainWindow", "Continue"))
        self.q1_label.setText(_translate("MainWindow", "Did you notice any differences before and after the modifications? Do not consider differences in questions asked in the web browsing task."))
        self.q1_yes_btn.setText(_translate("MainWindow", "Yes"))
        self.q1_no_btn.setText(_translate("MainWindow", "No"))
        self.q3_label.setText(_translate("MainWindow", "The modifications made to the system after the first round of tasks slowed down this computer. Did you notice that this computer was running slower after the modifications were applied?"))
        self.q3_yes_btn.setText(_translate("MainWindow", "Yes"))
        self.q3_no_btn.setText(_translate("MainWindow", "No"))
        self.q2_label.setText(_translate("MainWindow", "How were things different after the modifications were made? Please be descriptive."))
        self.q4_label.setText(_translate("MainWindow", "If you had to guess by what percentage this computer was made slower in the second set of tasks, what would your guess be? For example, if a computer could normally open a web browser in 1 second and was slowed down by 50%, the slowed-down computer could open a web browser in 1.5 seconds. By what percentage do you think this computer was slowed down?"))
        self.wta_yes_btn.setText(_translate("MainWindow", "Yes"))
        self.wta_no_btn.setText(_translate("MainWindow", "No"))
        self.wta_label.setText(_translate("MainWindow", "Would you be willing to accept a permanent 30% slowdown on your own computer in exchange for:"))
        self.wta_disclaimer_label.setText(_translate("MainWindow","This is for your current computer only and does not apply to any future computers you may buy."))
        self.wta_offer.setText(_translate("MainWindow", "$1"))



