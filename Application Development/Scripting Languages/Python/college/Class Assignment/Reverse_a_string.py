name = str(input("Enter a string: "))
length = len(name)
# Reversing the string
reversed_string =''
for i in range (length):
  reversed_string +=name[length-1-i]

print(reversed_string)