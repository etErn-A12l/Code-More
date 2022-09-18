# Input = 12
# Outout should be 1+2 = 3

number = input("Type a two digit number: ")

number = str(number)    # Converting Number to String

sum = int(number[0]) + int(number[1])   # Extracting the two digits then adding as Intejers

print(sum)  # Printing the result