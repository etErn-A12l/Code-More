# 🚨 Don't change the code below 👇
age = input("What is your current age?")
# 🚨 Don't change the code above 👆

# Write your code below this line 👇

years = 90 - int(age)   # Assumed the we will live 90 years
x = years * 365
y = years * 52
z = years * 12
# print(type(z))
print(f"You have {x} days, {y} weeks, and {z} months left.")
