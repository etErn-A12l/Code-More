
# Creating Empty Dictionary


dict1 = {}

# Dictoinary with number keys

dict2 = {1: "Kolkata", 2: "Mumbai"}

# Dictionary with mixed leys

dict3 = {'city': 'Kolkata', 1: [2, 4, 3]}

# using dict() function

dict4 = dict({1: 'Kolkata', 2: 'Delhi'})

# from sequence having each item as a pair

dict5 = dict([(1, 'Kolkata'), (2, 'Delhi')])


# **************************************************** #

# Accessing the data in a dictionary

dict1 = {'Subject': 'Computer', 'Mark': 86}

print(dict1['Subject'])    # Output: Computer
print(dict1.get('Mark'))   # Output: 86

print(dict2.get(5))         # Output: None
# print(dict2[5])             # Output: KeyError


thisdict = {
    "Name": "Sreejan", "Subject": "Physics", "Roll": "Sreejan"}

print(thisdict["Roll"])     # Output: 10

# The keys() method will return a list of all the keys in the dictionary.

print(thisdict.keys())

# The values() method will return a list of all the values in the dictionary.

print(thisdict.values())

# The items() method will return each item in a dictionary, as tuples in a list.

print(thisdict.items())


# To determine if a specified key is present in a dictionary use the in keyword:

if "Roll" in thisdict:
    print("Yes, 'Roll' is one of the keys in the thisdict dictionary")


# Create a dictionary from two lists using fromkeys()

x = ('key1', 'key2', 'key3')
y = 0

thisdict1 = dict.fromkeys(x, y)

# {'key1': 0, 'key2': 0, 'key3': 0}

print(thisdict1)

keys = ['a', 'b', 'c', 'd', 'e']
values = [1, 2, 3, 4, 5]

myDict = {k: v for (k, v) in zip(keys, values)}
myDict = dict(zip(keys, values))    # Same

# **************************************** #

# Update value

thisdict1['key1'] = 'History'

# Add in the same way

thisdict1['key4'] = 1

print(thisdict1)

print(thisdict1.popitem(), end="")       # Deletes and returns the last item
print(" item was popped")

print(thisdict1)

# Deletes the specified key and returns the value
print(thisdict1.pop('key2'), end="")
print(" Item Was popped")

print(thisdict1)


# ************************************** #

# Loop through the dictionary

for x in thisdict:
    print(thisdict[x])  # Prints the Values

# /////

for x in thisdict:
    print(x)    # Prints the Keys

for x in thisdict.values():
    print(x)    # Prints the Values

for x in thisdict.keys():
    print(x)    # Prints the Keys

for x, y in thisdict.items():
    print(x, y)     # Prints items


# ******************************* #

# Nested Dictionary

Father = {
    'sun': dict1,
    'mon': dict2,
    'tue': dict3,
    'wed': dict4
}

print("\n")

for x, y in Father.items():
    print(x, y)


Mother = Father.copy()

print(Mother)
