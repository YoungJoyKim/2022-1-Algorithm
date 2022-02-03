import sys

n = int(sys.stdin.readline().rstrip())
for i in range(n):
    a, b = n = sys.stdin.readline().rstrip().split()
    a = int(a)
    b = int(b)
    print(a + b)
