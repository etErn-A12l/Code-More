# Write your code below this line 👇
def prime_checker(number):
    if number == 2 or number == 1:
        print("It's a prime number.")
        return
    prime = True
    for i in range(2, number):
        if number % i == 0:
            prime = False
            break
    if prime == True:
        print("It's a prime number.")
    else:
        print("It's not a prime number.")


# Write your code above this line 👆
# Do NOT change any of the code below👇
n = int(input("Check this number: "))
prime_checker(number=n)
