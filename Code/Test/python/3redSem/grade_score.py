subject = []

for i in range(5):
    print(f"Enter marks for {i+1}th Subject: ",end="")
    marks = int(input())
    subject.append(marks)
    print()

total = 0
for i in range(5):
    total += subject[i]

avg = total / 5

if avg > 90 and avg <= 100:
    print("O")
elif avg > 80 and avg <= 90:
    print("E")
elif avg > 70 and avg <= 80:
    print("A")
elif avg > 60 and avg <= 70:
    print("B")
elif avg > 50 and avg <= 60:
    print("C")
else:
    print("F")