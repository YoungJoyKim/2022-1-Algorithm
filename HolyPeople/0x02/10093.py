a, b = input().split()
a = int(a)
b = int(b)

if a > b:
    a, b = b, a
if a == b or b - a == 1:
    count = 0
else:
    print(b - a - 1)
    for i in range(a + 1, b):
        print(i, end=' ')
