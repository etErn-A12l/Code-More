import enum


my_list = [1,2,3,4,"a","b","c", True, [1,2,3], "value"]

print(type(my_list))

my_list.append("Hacking")

print(my_list)

#len(my_list) -1

course = ["Ethical Hacking"] * 20

print(course)

my_numbers = [2,9,1,10,33,50]

#first = my_numbers[0]
#second = my_numbers[1]

#one,two,three,four,five,six = my_numbers

#one,two, *other = my_numbers
#print(one)
#print(two)
#print(*other)

letters = ["a","b","c","d"]
for i in letters : 
    print(i)
    
for i in enumerate(letters):
    print(i)
    
my_numbers.sort(reverse=True)

print(my_numbers)

print(sorted(my_numbers) )

my_numbers.insert(1,"test")

print(my_numbers)

my_numbers.remove(9)

print(my_numbers)
