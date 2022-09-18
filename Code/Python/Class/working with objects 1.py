
class person1:
    def __init__(self, cars, bikes):
        self.cars = cars
        self.bikes = bikes

    def func(self):
        print("The number of bikes I have is " + self.bikes)


p1 = person1("Kawasaki", 3)
p1.func()


# class Person:
#   def __init__(self, name, age):
#     self.name = name
#     self.age = age

#   def myfunc(self):
#     print("Hello my name is " + self.name)

# p1 = Person("John", 36)
# p1.myfunc()
