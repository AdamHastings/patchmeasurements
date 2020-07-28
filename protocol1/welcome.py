import os
import textwrap
import sys

def welcome():
    
    os.system('cls' if os.name == 'nt' else 'clear')

    name=input("Please type your name to begin: ")

    os.system('cls' if os.name == 'nt' else 'clear')

    print(textwrap.fill("Thank you " + name + " for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 20 minutes to complete."))
    
    response=""
    while (response.lower() != "y" and response.lower() != "n"):
        response= input("\n\nDo you consent to participating in this experiment?\nPlease type y/n: ")
    if (response.lower() == "n"):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("\n\nThanks for your participation.\n\n")
        sys.exit()
    else:
        return name


def finish():
    os.system('cls' if os.name == 'nt' else 'clear')
    print("Thanks for you participation! You are now finished. Please do not discuss the details of this experiment with others.\n\nYou may return the laptop to Adam")

    cleanup=""
    while (cleanup != "save"):
        cleanup=input()
    
    os.system("./throttle 2000MHz  > /dev/null 2>&1")
    return
