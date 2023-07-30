class ParentClass:
    def print_self(self):
        print("Parent")
 
class ChildClass(ParentClass):
    def print_self(self):
        print("Child")
 
child_instance = ChildClass()
child_instance.print_self()