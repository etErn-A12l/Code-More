class Animal:
    def __init__(self, name, legs):
        self.name = name
        self.legs = legs


class Dog(Animal):
    def sound(self):
        print("Woof!")


Yoki = Dog("Yoki", 4)
print(Yoki.name)  # => YOKI
print(Yoki.legs)  # => 4
Yoki.sound()  # => Woof!
