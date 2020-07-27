import textwrap
import time
import os
import sys

def setup():
    os.system("./throttle 2000MHz  > /dev/null 2>&1")
    os.system('cls' if os.name == 'nt' else 'clear')
    print(textwrap.fill("This experiment is designed to test how computer users respond to some computer system modifications we are prototyping. We will first have you complete some simple tasks with these modifications turned off. Later, we will turn on these modifications and ask you to complete the same set of tasks."))

    response=""
    while (response.lower() != "y" and response.lower() != "n"):
        response= input("\n\nDo you understand and wish to continue?\nPlease type y/n: ")
    if (response.lower() == "n"):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("\n\nThanks for your participation.\n\n")
        sys.exit()
    else:
        return


def patch():
    os.system('cls' if os.name == 'nt' else 'clear')
    input(textwrap.fill("We are about halfway done. We will now make some modifications to this computer. You do not need to know the details of these modifications to continue. When you are ready, press Enter."))
    
    os.system("./throttle 800MHz  > /dev/null 2>&1")
    print("\n\nPlease wait while modifications are applied", end='', flush=True)

    for i in "............":
        # printing each character of the message
        print(i, end='', flush=True)
        time.sleep(0.3)

    print("done!")

    input(textwrap.fill("\n\nThis computer has now been modified. Please press Enter to continue"))


def wrapup():
    os.system('cls' if os.name == 'nt' else 'clear')
    print(textwrap.fill("We are now completed with all tasks. Thanks for your participation so far! To conclude this experiment, we will ask a series of questions about your experience.\n"), end="\n", flush=True)

    input("\nPress Enter when you are ready to continue")

    os.system('cls' if os.name == 'nt' else 'clear')
    
    diff=""
    while (diff.lower() != "n" and diff.lower() != "y"):
        diff=input(("Did you notice any differences before and after the modifications?\n\nType y/n and press Enter: "))
    
    os.system('cls' if os.name == 'nt' else 'clear')

    if (diff.lower() == "y"):
        diffresp = input("How were things different after the modifications were made? Please be descriptive.\n\nType your response and then press Enter: ")
        diffresp = '"' + diffresp + '"'
    else:
        diffresp = ""
    
    os.system('cls' if os.name == 'nt' else 'clear')

    print(textwrap.fill("The modifications made to the system after the first round of tasks slowed down this computer. Did you notice that this computer was running slower after the modifications were applied?"))

    slower = ""
    while (slower.lower() != "y" and slower.lower() != "n"):
        slower=input("\nType y/n and press Enter: ")

    os.system('cls' if os.name == 'nt' else 'clear')

    print(textwrap.fill("If you had to guess by what percentage this computer was made slower in the second set of tasks, what would your guess be? For example, if a computer could normally open a web browser in 1 second and was slowed down by 50%, the slowed-down computer could open a web browser in 1.5 seconds. By what percentage do you think this computer was slowed down?"))

    percentage=input("\nPlease type your best guess and press Enter: ")

    os.system('cls' if os.name == 'nt' else 'clear')

    print(textwrap.fill("The actual amount this computer was slowed down by was 30%. We are now going to ask a series of questions to determine how much someone would have to pay you to permanently accept a 30% slowdown on your own computer.\n\n"))

    input("\nPress Enter when you are ready to continue")

    return diff,diffresp,slower,percentage
