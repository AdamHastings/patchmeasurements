from expsearch import get_WTA
from browser import browser
from setup import *
from welcome import welcome
from solitaire import solitaire

name = welcome()
#setup()
#solitaire()
#browser(1)
#patch()
#solitaire()
#browser(2)
diff, diffresp, slower, percentage = wrapup()
#WTA= get_WTA()
print(diff, diffresp, slower, percentage)
print(WTA)
