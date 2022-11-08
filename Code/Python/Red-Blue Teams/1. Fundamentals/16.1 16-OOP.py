class Test :
    def __init__(self,a, b ,c) :
        self.a = a
        self.b = b
        self.c = c
    def first(self) :
        print("first method")
    def values(self):
        print(f"a value of a attr is {test.a} \na value of b attr is {test.b} \na value of c attr is {test.c}")
        
test = Test(1,2,3)
test.values()

print(isinstance(test, Test))
