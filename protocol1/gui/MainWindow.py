import sys
from PyQt5.QtWidgets import QApplication, QMainWindow

from Ui_MainWindow import Ui_MainWindow

class MainWindow:
    def __init__(self):
        self.main_win = QMainWindow()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self.main_win)
                
        self.ui.stackedWidget.setCurrentWidget(self.ui.start_page)

        #self.ui.blu_btn.clicked.connect(self.showBlue)
        #self.ui.red_btn.clicked.connect(self.showRed)
        #self.ui.ylw_btn.clicked.connect(self.showYellow)

        self.ui.not_consent_btn.clicked.connect(self.showGoodbye)
        self.ui.consent_btn.clicked.connect(self.showTask1)
        self.ui.task1_continue_btn.clicked.connect(self.showPatch)
        self.ui.patch_continue_btn.clicked.connect(self.showTask2)
        self.ui.task2_continue_btn.clicked.connect(self.showQ1)
        self.ui.q1_yes_btn.clicked.connect(self.q1Response)
        self.ui.q1_no_btn.clicked.connect(self.q1Response)
        self.ui.q1_continue_btn.clicked.connect(self.showQ2)
        self.ui.q2_continue_btn.clicked.connect(self.showQ3)
        self.ui.q3_continue_btn.clicked.connect(self.showQ4)
        self.ui.q3_yes_btn.clicked.connect(self.q3Response)
        self.ui.q3_no_btn.clicked.connect(self.q3Response)
        self.ui.q4_continue_btn.clicked.connect(self.showWTA)

    def show(self):
        self.main_win.show()

    def showGoodbye(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.goodbye_page)

    def showTask1(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.task1_page)

    def showPatch(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.patch_page)

    def showTask2(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.task2_page)

    def showQ1(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.q1_page)
    
    def q1Response(self):
        self.ui.q1_continue_btn.setEnabled(True)

    def showQ2(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.q2_page)

    def showQ3(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.q3_page)

    def q3Response(self):
        self.ui.q3_continue_btn.setEnabled(True)

    def showQ4(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.q4_page)

    def showWTA(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.wta_page)

    #def showBlue(self):
    #    self.ui.stackedWidget.setCurrentWidget(self.ui.Blue_page)

    #def showRed(self):
    #    self.ui.stackedWidget.setCurrentWidget(self.ui.Red_page)

    #def showYellow(self):
    #    self.ui.stackedWidget.setCurrentWidget(self.ui.Yellow_page)


if __name__=='__main__':
    app = QApplication(sys.argv)
    main_win = MainWindow()
    main_win.show()
    sys.exit(app.exec())
