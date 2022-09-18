class ParentClass:
    def printtest(self):
        print("Parent Method")
 
class ChildClass(ParentClass):
    def print_test(self):
        print("Child Method")
        # Calls the parent's print_test()
        super().printtest() 

child_instance = ChildClass()
child_instance.print_test()

