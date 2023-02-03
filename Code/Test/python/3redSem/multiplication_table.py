num = int(input("Enter the number: "))
ren = int(input("Enter the range: "))

print("Below is the multiplication Table: \n")
for i in range(ren):
    print(f"{num} X {i+1} = {num*(i+1)}")