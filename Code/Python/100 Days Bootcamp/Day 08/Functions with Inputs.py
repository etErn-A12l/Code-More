
# Function with no arguments
def greet():
    print('Good Morning')
    print('Make this day count')


# Function with arguments
def greet_with_name(name):
    print(f"Good night {name}")
    print(f"{name} you are awesome")


def greet_with(name, size):
    print(f"Hello there, I am {name} and my size is {size}")


greet_with_name("xron")
# Calling Function with positional arguments
greet_with("xron", "75 kgs")
# Calling Function with keyword arguments
greet_with(size="75 kgs", name="xron")   # Order doesn't matter
