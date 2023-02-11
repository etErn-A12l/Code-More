temp = {"a" : "foo", "b" : "bar"}

new_dict = dict(x=1,y=2)

print(type(new_dict))

print(temp.get("a"))

print(temp.get("x"))

print(temp.get("x","test"))

temp2 = dict(temp)
temp2["z"] = "newValue"
print(temp2)

print(temp.keys())
print(temp.values())
print(temp.items())

print("a" in temp)

print("foo" in temp.values())

for key in temp :
    print(key, temp[key])
    
del temp["a"]
print(temp)

example = {x : x * 3 for x in range(4)}

print(example)
