

# upper() returns a specific string in upper case

a1 = " Hello I am Sreejan "
print(a1.upper())

# lower() returns a specific string in lwer case characters

a2 = "Hi THere"
print(a2.lower())

#strip() removes unnecessary spaces from beginning and end

a3 = "   ~I love Someone but she don't loves me~   "
print(a3.strip())

#Replaces string

a4 = "Hello, World!"
print(a4.replace("H", "J"))     # returns "Jello, World!" 

#Split a string

a = "Hello, World!"
print(a.split(",")) # returns ['Hello', ' World!'] 

b = " i love mnkey and you cuz u and monkey r same"

print(b.split("o"))

print(a.encode())

print(a.rjust(30))

print(a.rjust(30,"R"))

print(a.ljust(30,"~"))
