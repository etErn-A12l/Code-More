from unittest import result


def f(x):
    d=0
    while x >= 1:
        (x,d) = (x/7,d+1)
    return(d)

result = f(3456)

print(result)