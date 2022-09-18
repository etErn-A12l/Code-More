dick = {"ami": 10, "tumi": 5, "se": 1}

print(dick)

print(dick["ami"])
print(dick.get("ami"))

print(dick.keys())
print(dick.items())
print(dick.values())

dick["ami"] = 50

dick["onno_keu"] = 0

print(dick)

dick.pop("onno_keu")
del dick["se"]

print(dick)

dick["arekjon"] = {"a": 2, "b": 3, "c": 4}
print(dick)

dick.pop("arekjon")

print(dick)

dick3 = {}
dick2 = dict()
