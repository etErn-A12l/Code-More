n = int(input("Enter the size of list"))
lst = []


def bubble_sort(lst, n):

    for j in range(0, n - 1):

        flag = 0
        for k in range(0, n - 1 - j):
            if lst[k] > lst[k + 1]:
                temp = lst[k]
                lst[k] = lst[k + 1]
                lst[k + 1] = temp
                flag = 1
        if flag == 0:
            break
    print("The sorted list is:", lst)





def binary_search(lst, n, data):
    found = 0
    l = 0
    r = n - 1
    while l <= r:
        mid = int((l + r) / 2)
        if data == lst[mid]:
            print("The data is found in position", mid + 1)
            found = 1
            break
        elif data < lst[mid]:
            r = mid - 1
        else:
            l = mid + 1
    if l > r and found == 0:
        print("the  data is not found")


for i in range(0, n):
    x = int(input())
    lst.append(x)
bubble_sort(lst, n)
val = int(input("Enter the data to be searched"))
binary_search(lst, n, val)
