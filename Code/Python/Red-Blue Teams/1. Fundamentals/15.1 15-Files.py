# R , W , A , RT, RB

import os
print(os.path.exists("file.txt"))
print(os.listdir("c:\\"))

handle = open("file.txt","a")

handle.write("\nthird line")
handle.close()
listoflines = handle.readlines()

handle.close()

print(listoflines)

for i in handle :
   print(i, end=", ")

with open("file.txt", "a") as files :
   files.write("\ntest message with with open method")
