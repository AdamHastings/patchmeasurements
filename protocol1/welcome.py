import os
import textwrap
import sys

def welcome():
    
    os.system('cls' if os.name == 'nt' else 'clear')

    print(textwrap.fill("\n\nThank you for participating in this experiment. This experiment will have you complete a few simple tasks on this computer. This experiment does not track your actions or steal any personal information. There is minimal risk involved in participating in this experiment. This experiment will take about 15 minutes to complete."))
    
    response=""
    while (response.lower() != "y" and response.lower() != "n"):
        response= input("\n\nDo you consent to participating in this experiment?\nPlease type y/n: ")
    if (response.lower() == "n"):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("\n\nThanks for your participation.\n\n")
        sys.exit()
    else:
        return
