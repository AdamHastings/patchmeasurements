import sys, os
from PyQt5.QtWidgets import QApplication, QMainWindow

from Ui_MainWindow import Ui_MainWindow

class MainWindow:
    def __init__(self):
        self.main_win = QMainWindow()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self.main_win)
                
        self.ui.stackedWidget.setCurrentWidget(self.ui.start_page)
        self.ui.not_consent_btn.clicked.connect(self.showGoodbye)
        self.ui.consent_btn.clicked.connect(self.showTask1)
        self.ui.task1_continue_btn.clicked.connect(self.showPatch)
        self.ui.patch_continue_btn.clicked.connect(self.showTask2)
        self.ui.task2_continue_btn.clicked.connect(self.showQ1)
        self.ui.q1_yes_btn.clicked.connect(self.q1Response)
        self.ui.q1_no_btn.clicked.connect(self.q1Response)
        self.ui.q1_continue_btn.clicked.connect(self.showQ1Next)
        self.ui.q2_continue_btn.clicked.connect(self.showQ3)
        self.ui.q3_continue_btn.clicked.connect(self.showQ4)
        self.ui.q3_yes_btn.clicked.connect(self.q3Response)
        self.ui.q3_no_btn.clicked.connect(self.q3Response)
        self.ui.q4_continue_btn.clicked.connect(self.showWTA)
        self.ui.wta_yes_btn.clicked.connect(self.updateOffer_yes)
        self.ui.wta_no_btn.clicked.connect(self.updateOffer_no)
        self.ui.goodbye_close_btn.clicked.connect(self.close)

        self.wta_offer_value = 1
        self.wta_upper = -1
        self.wta_lower = -1
        self.first_accept = False

    def show(self):
        self.main_win.show()
        # Temp set freq. Works for linux only. TODO make cross platform
        os.system("./throttle 1200MHz  > /dev/null 2>&1")

    def showGoodbye(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.goodbye_page)

    def close(self):
        # Restore clock speed
        os.system("./throttle 1200MHz  > /dev/null 2>&1")
        sys.exit()

    def showTask1(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.task1_page)

    def showPatch(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.patch_page)
        
        # Lower clock speed
        os.system("./throttle 800MHz  > /dev/null 2>&1")

    def showTask2(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.task2_page)

    def showQ1(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.q1_page)
    
    def q1Response(self):
        self.ui.q1_continue_btn.setEnabled(True)

    def showQ1Next(self):
        if self.ui.q1_yes_btn.isChecked():
            self.ui.stackedWidget.setCurrentWidget(self.ui.q2_page)
        else:
            self.ui.stackedWidget.setCurrentWidget(self.ui.q3_page)

    def showQ3(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.q3_page)

    def q3Response(self):
        self.ui.q3_continue_btn.setEnabled(True)

    def showQ4(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.q4_page)

    def showWTA(self):
        self.ui.wta_offer.setText("$" + str(self.wta_offer_value))
        self.ui.stackedWidget.setCurrentWidget(self.ui.wta_page)

    def updateOffer_yes(self):
        if self.wta_offer_value < 4:
            print(self.wta_offer_value)
            self.ui.stackedWidget.setCurrentWidget(self.ui.goodbye_page)
        elif not self.first_accept:
            self.first_accept = True
            self.upper = self.wta_offer_value
            self.lower = self.wta_offer_value/2
            self.wta_offer_value = int((self.lower + self.upper)/2)
            self.showWTA()
        else:
            self.upper = self.wta_offer_value
            self.wta_offer_value = int((self.lower + self.wta_offer_value)/2)
            if (self.upper - self.lower <= 2):
                print(self.wta_offer_value)
                self.ui.stackedWidget.setCurrentWidget(self.ui.goodbye_page)
            else:
                self.showWTA()

      

    def updateOffer_no(self):
        if not self.first_accept:
            self.wta_offer_value *= 2
            self.showWTA()
        else:
            self.lower = self.wta_offer_value
            self.wta_offer_value = int((self.wta_offer_value + self.upper)/2)
            if (self.upper - self.lower <= 2):
                print(self.wta_offer_value)
                self.ui.stackedWidget.setCurrentWidget(self.ui.goodbye_page)
            else:
                self.showWTA()

    

    


if __name__=='__main__':
    app = QApplication(sys.argv)
    main_win = MainWindow()
    main_win.show()
    sys.exit(app.exec())
