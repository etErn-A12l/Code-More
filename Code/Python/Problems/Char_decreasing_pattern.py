n = int(input())
a = []
for i in range(n):
    a.append(chr(97+i))
b = a[::-1]
l = []
for i in range(1, n+1):
    print('-'*((n-i)*2), end='')
    print('-'.join(b[:i]+a[-1:-i:-1][::-1]), end='')
    print('-'*((n-i)*2))
    l.append(str('-'((n-i)*2)) + str('-'.join(b[:i]+a[-1:-i:-1][::-1]))+str('-'((n-i)*2)))
l = l[::-1]
for j in l:
    print(j)
