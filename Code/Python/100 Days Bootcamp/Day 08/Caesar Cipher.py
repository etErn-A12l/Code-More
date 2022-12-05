from art import *

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
            'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']


def caesar(input_text, shift_amount, stated_direction):

    new_text = ""

    for letter in input_text:
        if letter not in alphabet:
            new_text += letter
        else:
            index = alphabet.index(letter)
            if stated_direction == "encode":
                new_index = (index + shift_amount) % len(alphabet)
                new_text += alphabet[new_index]
            elif stated_direction == "decode":
                new_index = index - shift_amount
                if new_index < 0:
                    new_index = len(alphabet) + new_index
                new_text += alphabet[new_index]
            else:
                print("Wrong input !")
                return
    print(f"\nResult: {new_text}\n")


# Driver Code
run = True
print(logo)

while run:

    direction = input("Type 'encode' to encrypt, type 'decode' to decrypt: ")
    text = input("\nType your message: ").lower()
    shift = int(input("Type the shift number: "))
    shift = shift % len(alphabet)

    caesar(input_text=text, shift_amount=shift, stated_direction=direction)

    restart = input(
        "Type 'yes' if you want to go again. Otherwise type 'no': ")
    if restart == "no":
        run = False
        print("\nGoodbye")
