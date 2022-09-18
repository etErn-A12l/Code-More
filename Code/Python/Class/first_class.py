
class ami:
    a = 4


p = ami()
print(p.a)


# The __init__() Function

class Marksheet:
    def __init__(self, physics, chemistry, mathematics):
        self.phy = physics
        self.chem = chemistry
        self.math = mathematics


M1 = Marksheet(82, 80, 66)

print("The marks of your Physics paper is {} ".format(M1.phy))
print("The marks of your Chemistry paper is %s" % (M1.chem))
print(M1.math)
