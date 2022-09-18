# and

# or

apple = float(input("What is the price of apple ? "))

if apple > 20 and apple < 30:
    print("The price is Normal")
elif apple >= 30 and apple < 40:
    print("The price is slightly high !")
elif apple < 20 or apple > 40:
    print("The price or the shopkeeper is abnormal !")
