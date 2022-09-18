from hashlib import new


magicians = ['alice','james','tom','bob']

for magician in magicians:
    print(f"Hi {magician.title()}, how are you ?") # the .title() capitalizes first letter


squares = []
for i in range(1,20):
    squares.append(i**2)

print(squares)

print(min(squares))
print(max(squares))

squares = [value**2 for value in range(1, 11)]  # Does same as the previous expression
print(squares)

players = ['charles', 'martina', 'michael', 'florence', 'eli']
print("Here are the first three players on my team:")
for player in players[:3]:  # Looping from sliced list
    print(player.title())

new_players = players

print(new_players)