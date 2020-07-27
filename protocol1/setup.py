import textwrap
import os
import sys

def setup():
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

