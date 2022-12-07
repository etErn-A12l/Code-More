import os
list = os.environ["PATH"]

list1 = list.split(";")

for items in list1:
    print(items)