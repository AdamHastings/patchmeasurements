import sys
from PyQt5.QtWidgets import QApplication, QMainWindow

from Ui_MainWindow import Ui_MainWindow

class MainWindow:
    def __init__(self):
        self.main_win = QMainWindow()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self.main_win)
                
        self.ui.stackedWidget.setCurrentWidget(self.ui.Home)

        self.ui.blu_btn.clicked.connect(self.showBlue)
        self.ui.red_btn.clicked.connect(self.showRed)
        self.ui.ylw_btn.clicked.connect(self.showYellow)

    def show(self):
        self.main_win.show()

    def showBlue(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.Blue_page)

    def showRed(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.Red_page)

    def showYellow(self):
        self.ui.stackedWidget.setCurrentWidget(self.ui.Yellow_page)


if __name__=='__main__':
    app = QApplication(sys.argv)
    main_win = MainWindow()
    main_win.show()
    sys.exit(app.exec())
