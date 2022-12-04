# Password Generator Project
import random
import pyfiglet
import os

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
           'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&',
           '(', ')', '*', '+', '-', '_', '=', '`', '~', '<', '>', '?', '.', ',']

set = [letters, numbers, symbols]

choice = 'y'

while choice == 'y':
    os.system('cls')
    print(pyfiglet.figlet_format("Passwd", font="5lineoblique"))
    nr_letters = int(
        input("\nNumber of letters would you like in your password: "))

    passwd = []

    for i in range(nr_letters):
        chosen_set = random.choice(set)
        key = random.choice(chosen_set)
        passwd += key

    print(f"\n{''.join(passwd)}")

    choice = input("\nRegenerate password ? (Y/n): ").lower()


# Eazy Level - Order not randomised:
# e.g. 4 letter, 2 symbol, 2 number = JduE&!91


# Hard Level - Order of characters randomised:
# e.g. 4 letter, 2 symbol, 2 number = g^2jk8&P
