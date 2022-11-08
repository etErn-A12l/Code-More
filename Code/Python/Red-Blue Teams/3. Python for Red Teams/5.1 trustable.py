import os

while True :
    user_input = str(input("Enter your value : " ))
    print(user_input)
    print("process id is : " + str(os.getpid()) + "\n")
