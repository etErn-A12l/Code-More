import sys

print(sys.getsizeof(tuple(range(1000000))))
print(sys.getsizeof(list(range(1000000))))

top = (1,2,3,4)

tops = 1,2,3,4,5

print(type(top))
print(type(tops))

best = (1,2)

print(best * 3)

my_list = [1,2,3,4]

new_tuple = tuple(my_list)

print(new_tuple)

one,two = best

print(one)
print(two)


