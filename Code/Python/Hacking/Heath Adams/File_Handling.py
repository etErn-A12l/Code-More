
f = open('abcd.txt')
print(f)

f = open('abcd.txt', 'rt')  # rt stands for read text
print(f)

# print(f.read()) # prints what it reads

# f.seek(0)
    
# Moves the pointer to the beginning of the file to read again

# print(f.readlines()) # prints all words as elements of an array

f.seek(0)
for line in f:
    print(line.strip())

# f = open('abcd.bat', 'w')   # w stands for write
# f.write('I Love You')
# f.close()

# print(f.name)
# print(f.closed)
# print(f.mode)
