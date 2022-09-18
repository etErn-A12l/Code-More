
class person:
    def __init__(self, cars, bikes):
        self.cars = cars
        self.bikes = bikes

    def func(self):
        print("The number of bikes I have is " + self.bikes)


p1 = person("Kawasaki", 3)
p1.func()
