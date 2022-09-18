
print("Welcome to the rollercoaster !")
height = int(input("What is your height in cm ? "))

bill = 0
if height > 120:

    print("You can ride rollercoaster.")
    age = int(input("What is your age ? "))

    if age < 12:

        bill = 5
        print("Ticket for children: $5")

    elif age <= 18:

        bill = 7
        print("Ticket for youths: $7")

    else:

        bill = 12
        print("Ticket for adults: $12")

    wants_photo = input("Do you want a photo ? (Y/N): ")
    if wants_photo == "Y" or wants_photo == "y":
        bill += 3

    print(f"Your Total bill is ${bill}")
else:
    print("Sorry you can't ride rollercoaster.")
  