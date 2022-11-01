
# 1) Empty tuple

tuple1 = ()
print(tuple1)

# 2) Tuple having integer data-types

tuple2 = (10, 15, 20)
print(tuple2)

# 3) tuple with mixed data-types

tuple3 = (1, "Hello", 3.4)
print(tuple3)

# 4) nested tuple

tuple4 = ("mouse", (8, 4, 6), (1, 2, 3))
print(tuple4)

# A tuple can also be created without using parentheses. This is known as tuple packing.

tuple5 = 1, 1.1, "hi"
print(tuple5)

# Tuple unpacking is also possible

a, b, c = tuple5
print(a)
print(b)
print(c)

# Since tuples are indexed, they can have items with the same value:

tuple6 = ("Kolkata", "Agra", " Delhi ", " Kolkata ", "Agra")
print(tuple6)


tuple11 = ('C', 'O', 'M', 'P', 'U', 'T', 'E', 'R')
print(tuple11[:])
print(tuple11[1:4])

tuple7 = ("KOLKATA", "DELHI", "MUMBAI")

if "DELHI" in tuple7:
    print("Yes, ' DELHI ' is in the CITY tuple")


# Add tuple to a tuple:

tuple8 = ("KOLKATA", "DELHI", "MUMBAI")
y = (" CHENNAI ",)
tuple8 = tuple8 + y
print(tuple8)

# Deletion

tuple9 = ("KOLKATA", "DELHI", "MUMBAI") 
y1 = list(tuple9) 
y1.remove("DELHI",) 
tuple9 = tuple(y1)
  
print(tuple9)

# Multiply Tuples

fruits = ("apple", "banana", "cherry") 
tuple = fruits * 2 
print(tuple)

# Count Method 

tuple12 = (11, 13, 17, 18, 17, 15, 14, 16, 18, 15) 
x = tuple12.count(17) 
print(x)

l1 = ["eat", "sleep", "repeat"]
s1 = "geek"
# creating enumerate objects
obj1 = enumerate(l1)
obj2 = enumerate(s1)
print ("Return type:", type(obj1))
print (list(enumerate(l1)))