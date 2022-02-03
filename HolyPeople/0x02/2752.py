arr = input().split()
for i, v in enumerate(arr):
    arr[i] = int(v)
arr.sort()

for i in arr:
    print(i, end=' ')
