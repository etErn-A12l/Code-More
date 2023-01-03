# while True:
    
#     try:
#         num = int(input("Enter a number: "))
#     except ValueError: 
#         print("Please Enter a number !")
#     else:
#         break

from os import path


a = path.expandvars(r'%APPDATA%\Python-Passwd-Data')

if a != 2:
    print("a is not integer")
