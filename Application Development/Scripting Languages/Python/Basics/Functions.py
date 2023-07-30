
def firstfun():
    print("This is the first ever function")

firstfun()

def secondfun(a,b):
    print(a," ",b)

secondfun(2,3)

def thirdfun(*kids):
  print("The youngest child is " + kids[1])

thirdfun("Emil", "Tobias", "Linus")

def my_function(country = "Norway"):
  print("I am from " + country)

my_function("Sweden")
my_function("India")
my_function()
my_function("Brazil")

def faltu_function():
    pass    # This function does nothing



