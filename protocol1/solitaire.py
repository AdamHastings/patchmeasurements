import sys
import os
import textwrap

def solitaire():
    os.system('cls' if os.name == 'nt' else 'clear')
    print(textwrap.fill("In this task you will play a game of solitaire. We do NOT care about how well you do in this game or how long you play. Just play until you can't make any more moves, or are bored and want to continue with the experiment. Once you are done, exit the game."))

    response= input("\n\nWhen you are ready, press Enter to start the game of solitaire")


    os.system("/usr/games/sol")
    
    response=""
    while(response.lower() != "done"):
        response = input("\n\nWhen you are done with this task and ready to continue, type 'done' and press Enter: ")
