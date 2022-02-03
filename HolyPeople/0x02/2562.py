import sys

max_num = 0
idx = 1
max_idx = 0
for i in range(9):
    n = int(sys.stdin.readline().rstrip())
    if n > max_num:
        max_num = n
        max_idx = idx
    idx += 1

print(max_num)
print(max_idx)
