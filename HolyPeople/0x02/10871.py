n, x = input().split()
arr = input().split()

for i in range(int(n)):
    if int(arr[i]) < int(x):
        print(arr[i], end=' ')
