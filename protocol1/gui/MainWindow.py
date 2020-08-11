#!/usr/bin/env python3

import sys, os, time
from PyQt5.QtWidgets import QApplication, QMainWindow
from Ui_MainWindow import Ui_MainWindow
from my_socket import send_results

class MainWindow:
    def __init__(self, screen):
        self.main_win = QMainWindow()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self.main_win, screen)
                
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

    def setFreq(self, freq):
        if (os.name == 'nt'): # Windows
            pass
        else: 
            arg = "./throttle " + str(freq) + " > /dev/null 2>&1"
            os.system(arg)


    def show(self):
        self.main_win.show()
        # Temp set freq. Works for linux only. TODO make cross platform
        self.setFreq(1200)

    def showGoodbye(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.goodbye_page)

    def close(self):
        # Restore clock speed
        self.setFreq(1200)
        sys.exit()

    def showTask1(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.task1_page)

    def showPatch(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.patch_page)
        # Lower clock speed
        self.setFreq(800)

        magic_thresh = 24

        for i in range(magic_thresh):
            self.ui.progress_bar.setValue(i)
            time.sleep(0.1)

        for i in range(100 - magic_thresh):
            self.ui.progress_bar.setValue(i + magic_thresh + 1)
            time.sleep(0.01)

        self.ui.patch_continue_btn.setEnabled(True)

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
            self.conclude()
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
                self.conclude()
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
                self.conclude()
                self.ui.stackedWidget.setCurrentWidget(self.ui.goodbye_page)
            else:
                self.showWTA()

    def conclude(self):
       # Concatenate results and send to server
        if (self.ui.q1_yes_btn.isChecked()):
            q1_answer = "y"
            # TODO replace any comma
            q2_answer = self.ui.q2_input.toPlainText()
            q2_answer = q2_answer.replace(",", "")
        else:
            q1_answer = "n"
            q2_answer = ""

        if self.ui.q3_yes_btn.isChecked():
            q3_answer = "y"
        else:
            q3_answer = "n"
        
        q4_answer = self.ui.q4_input.text()

        wta = self.wta_offer_value

        result = ','.join(str(x) for x in [q1_answer, q2_answer, q3_answer, q4_answer, wta])
        send_results(result)
    


if __name__=='__main__':
    app = QApplication(sys.argv)
    screen = app.primaryScreen()
    main_win = MainWindow(screen)
    main_win.show()
    sys.exit(app.exec())
