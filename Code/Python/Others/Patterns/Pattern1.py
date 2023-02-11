# Python 3.x code to demonstrate star pattern

# Function to demonstrate printing pattern
"""
def pypart(n):
	
	# outer loop to handle number of rows
	# n in this case
	for i in range(0, n):
	
		# inner loop to handle number of columns
		# values changing acc. to outer loop
		for j in range(0, i+1):
		
			# printing stars
			print("* ",end="")
	
		# ending line after each row
		print("\r")

# Driver Code
n = 50
pypart(n)
"""

# My code

n = 5

for i in range(n):
    print("* " * (i + 1))
for j in range(n - 1):
    print("* " * (n - j - 1))

print("-" * 20)
print("-" * 20)

for i in range(n):
    print("  " * (n - 1 - i) + " *" * ((2 * i) + 1))
for j in range(n - 1):
    print("  " * (j + 1) + " *" * (2 * (n - 1) - 1 - (2 * j)))
