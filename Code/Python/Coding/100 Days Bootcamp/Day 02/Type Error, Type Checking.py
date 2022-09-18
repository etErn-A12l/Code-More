from unicodedata import name


name_len = len(input("What is your name ? "))  # Taking input from the user

print(type(name_len))  # checking the type of length of the given input

print(str(name_len))  # printing it as a string

name_len = str(name_len)  # Converting it into string data type

print(type(name_len))  # After conversion, Checking the type

print(70 + int("70"))   # Converting 70 from string to int, then printing the addition