
a = "Hehe"
b = "haha"
c = a+b
print(c)
print(a+b)  # Same
print(a+" "+b)


# Format strings
# format() is used to insert numbers in a string

age = 36
txt = "My name is John, and I am {}"
print(txt.format(age))

quantity = 3
itemno = 567
price = 49.95
myorder = "I want {} pieces of item {} for {} dollars."
print(myorder.format(quantity, itemno, price))

print("I am in love with {} but she dosen't know".format("bokachoda"))

# Use escape buttons to use quotes within quotes

print("I love Bokachoda \"Very Much\" but she dosen't know")

txt=txt.encode()
print(txt)


# Checks if x1 is a integer type data type

x1 = 200
print(isinstance(x1, int)) 