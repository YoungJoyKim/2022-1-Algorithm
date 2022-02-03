arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

for i in range(10):
    a, b = input().split()
    a = int(a)
    b = int(b)
    sublist = arr[a - 1:b]
    sublist.reverse()
    arr[a - 1:b] = sublist

for i in arr:
    print(i, end=' ')
