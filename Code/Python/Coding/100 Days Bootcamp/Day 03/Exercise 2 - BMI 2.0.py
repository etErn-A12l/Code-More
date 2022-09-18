# 🚨 Don't change the code below 👇
from telnetlib import BM


height = float(input("enter your height in m: "))
weight = float(input("enter your weight in kg: "))
# 🚨 Don't change the code above 👆

# Write your code below this line 👇

BMI = weight / height**2

if BMI < 18.5:
    print("Your BMI is {}, you are underweight.".format(round(BMI)))
elif BMI > 18.5 and BMI < 25:
    print("Your BMI is {}, you have a normal weight.".format(round(BMI)))
elif BMI > 25 and BMI < 30:
    print("Your BMI is {}, you are slightly overweight.".format(round(BMI)))
elif BMI > 30 and BMI < 35:
    print("Your BMI is {}, you are obese.".format(round(BMI)))
else:
    print("Your BMI is {}, you are clinically obese.".format(round(BMI)))
