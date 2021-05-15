import os

os.system("stty -echo")
password = input('Enter Password:')
os.system("stty echo")
print("")