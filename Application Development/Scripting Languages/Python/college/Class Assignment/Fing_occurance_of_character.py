input_string = str(input("Enter the string: "))
character = input("Enter the character you want to find: ")
length = len(input_string)
count = 0
for i in input_string:
  if i == character:
    count += 1

if count == 0:
  print(f"The character {character} is not present in the String !")
else:
  print(f"The character {character} is present {count} times in the String !")