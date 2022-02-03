import sys

n = int(sys.stdin.readline().rstrip())
data = sys.stdin.readline().rstrip().split()
x = int(sys.stdin.readline().rstrip())
arr = []
for i in data:
    arr.append(int(i))

numbers = [0] * 201
for i in arr:
    numbers[i + 100] += 1
print(numbers[x + 100])
