
# This program avoids errors generated for code failures

try:
    print('aluvate')
except:
    print("jani na")


try:
    kdfsjgvdkjsg = 0
except:
    print("jani na")


n = 'jyfiy'

if n == 0:
    raise Exception("The number is 0 !")
if type(n) is int:
    raise Exception("The type of the variable is not int")

print(n)

# ihih = 10   # cause of printing the value of ihih
ihih = 0    # cause of printing assertion error

assert(ihih != 0)
print(ihih)
