print("Welcome to tip calculator.")
amount = float(input("What was the total bill? $"))
tip_percent = int(input("What percentage tip would you like to give? 10, 12 or 15? "))
people = int(input("How many people to split the bill? "))

total_amount = amount + amount * tip_percent / 100
each_cost = round(float(total_amount / people), 2)

print(f"Each person should pay: ${each_cost}")