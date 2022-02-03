import sys

n = int(sys.stdin.readline().rstrip())
data = sys.stdin.readline().rstrip().split()
x = int(sys.stdin.readline().rstrip())
arr = []
check = [0] * 2000000
for i in data:
    arr.append(int(i))

cnt = 0
for i in arr:
    if x - i > 0 and check[x - i]:
        cnt += 1
    check[i] = 1
print(cnt)
