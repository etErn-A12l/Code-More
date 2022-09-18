import sys
import time
import math

# for i in range(999):
#     print(math.factorial(i))
#     print("\n")

# pip install slowprint
# from slowprint.slowprint import *
# slowprint("hello world")

def slowprint(s):
    for c in s + '\n':
        sys.stdout.write(c)
        sys.stdout.flush()
        time.sleep(1./10)
    slowprint("This is slowprint")