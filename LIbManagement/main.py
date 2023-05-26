# This is a sample Python script
import os

from Utility import *
from config import BLOCK_LENGTH
# Press the green button in the gutter to run the script.

if __name__ == '__main__':

    while True:
        displaySep("=", BLOCK_LENGTH)
        displayTitle("WELCOME TO LIBRARY MANAGEMENT SYSTEM", BLOCK_LENGTH)
        displaySep('-', BLOCK_LENGTH)
        showOptions()
        displaySep("-", BLOCK_LENGTH)
        command = int(input("Select Option: "))
        selectOption(command)
        input("Press Enter To continue..")
        os.system("cls")


