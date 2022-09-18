import random

fruits = ["orange", "apple", "pear", "banana", "kiwi", "apple", "banana"]

pen = ["Parker", "Cello", "Pere Cardin", "Shafard", "Link"]

list1 = [fruits, pen]  # Nested List

print(list1)

lenght_of_fruits = len(fruits)

length_of_pens = len(pen)

random_index = random.randint(0, lenght_of_fruits - 1)

print(fruits[random_index])