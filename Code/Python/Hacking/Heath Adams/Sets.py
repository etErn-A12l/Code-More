
set1 = {"a", "b", "c"}
print(type(set1))
print(len(set1))
print(set1)

set2 = {"ami", 8126, True, "tor baba"}

print(set2)

set1.update(set2)

print(set1)

print(len(set1))

set1.remove("tor baba")

print(set1)

set1.discard("ami")
print(set1)

set1.pop()
print(set1)
