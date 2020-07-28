import sys
import os
import textwrap

def browser(version):

    mapsloc1 = "the San Diego Zoo"
    mapsloc2 = "the Empire State Building"

    pictask1 = "a funny cat"
    pictask2 = "a cute dog"

    infotask1 = "the biggest city in Florida"
    infotask2 = "the biggest city in Brazil"

    if (version == 1):
        mapsloc=mapsloc1
        pictask=pictask1
        infotask=infotask1
    else:
        mapsloc=mapsloc2
        pictask=pictask2
        infotask=infotask2

    os.system('cls' if os.name == 'nt' else 'clear')
    print(textwrap.fill("In this task you will use a web browser to complete simple tasks. Specifically, your goal is to login to your email account and send an email to hastings@cs.columbia.edu that contains the following information:\n\n"))

    print("\t1) The street address of " + mapsloc)
    print("\t2) A picture of " + pictask)
    print("\t3) The name of " + infotask)
    
    

    print(textwrap.fill("\n\nOnce you are done, you may close the web browser."))

    input("\n\nWhen you are ready, press Enter to launch the web browser")
    os.system("sudo -H -u adam google-chrome --incognito > /dev/null 2>&1")

    response=""
    while(response.lower() != "done"):
        response = input("\n\nWhen you are done with this task and ready to continue, type 'done' and press Enter: ")
