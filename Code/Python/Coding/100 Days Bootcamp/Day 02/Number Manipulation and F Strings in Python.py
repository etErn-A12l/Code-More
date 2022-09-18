
print(8 / 3)  # returns a Float number

print(8 // 3)  # returns a whole number ( called flow division )

print(
    round(8 / 3)
)  # round function converts float to int according to the next decimal points

# we can also specify to where to start the rounding

print(
    round(8 / 3, 3)
)  # This ' ,3' argument helps to start rounding from 3 decimal points

# similarly

print(round(3.5555555555555, 4))  # this will round in 4 point


a = 12

a += 1

# Now, a == 13

apple = 12
banana = 23
carrot = 30

# F-String

print(f"Price of apple is {apple}, banana is {banana}, carrot is {carrot}")

# Classic way
print("Price of apple is {}, banana is {}, carrot is {}".format(apple,banana,carrot))