import os
import sys


file1 = open("results.txt", "a")
os.system('clear')
name = input("Please type your name: ")
os.system('cls' if os.name == 'nt' else 'clear')
x = 1
slowdown = str(20)
accept = False



while (not accept):
    response = input("Would you be willing to accept a permanent " + slowdown + "% slowdown on your own computer in exchange for \n\n\t$" + str(x) + "?\n\n Type yes or no: ")
    if (response.lower() == "y" or response.lower() == "yes"):
        accept = True
    elif (response.lower() == "n" or response.lower() == "no"):
        x *= 2
        os.system('cls' if os.name == 'nt' else 'clear')
    else:
        print("Please type 'yes' or 'no'")

if (x < 8):
    print("Thanks!")
    WTA = x
    file1.write(name + "," + str(WTA) + "\n")
    file1.close()
    sys.exit()

os.system('cls' if os.name == 'nt' else 'clear')

upper = x
lower = x/2
while (upper - lower > 2):
    midpoint = int((upper + lower)/2)
    response = input("Would you be willing to accept a permanent " + slowdown + "% slowdown on y    our own computer in exchange for \n\n\t$" + str(midpoint) + "?\n\n Type yes or no: ")

    if (response.lower() == "y" or response.lower() == "yes"):
        upper = midpoint        
    else:
        lower = midpoint

    os.system('cls' if os.name == 'nt' else 'clear')

print("Thanks!")
WTA = midpoint
file1.write(name + "," + str(WTA) + "\n")
file1.close()
sys.exit()
