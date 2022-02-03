import sys

n, k = sys.stdin.readline().rstrip().split()
n = int(n)
k = int(k)
arr = [[0] * 6, [0] * 6]

for i in range(n):
    s, y = sys.stdin.readline().rstrip().split()
    s = int(s)
    y = int(y)
    arr[s][y - 1] += 1

n_room = 0
for i in arr:
    for j in i:
        n_room += (j // k)
        if j % k != 0:
            n_room += 1

print(n_room)
