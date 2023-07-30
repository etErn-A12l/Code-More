def test() :
    print("first function")
    
def test_param(first_param, second_param) :
    print(f"{first_param} {second_param}")

def return_value(first_name):
    return f"welcome {first_name}"

my_message = return_value("Sara")

print(my_message)
