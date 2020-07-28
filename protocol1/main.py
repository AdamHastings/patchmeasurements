from expsearch import get_WTA
from browser import browser
from setup import *
from welcome import *
from solitaire import solitaire

# Run experiment
name = welcome()
freqs = setup()
print(freqs)
solitaire()
browser(1)
freqs2 = patch()
solitaire()
browser(2)
diff, diffresp, slower, percentage = wrapup()
WTA= get_WTA()
finish()

# Append results to file
log = open("log.txt", "a")
log.write(",".join([name, diff, diffresp, slower, percentage, str(WTA), freqs, freqs2, "\n"]))
