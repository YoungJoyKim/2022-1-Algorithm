mult = 1
arr = [0] * 10
for i in range(3):
    mult *= int(input())

for i in str(mult):
    arr[ord(i) - ord('0')] += 1

for i in arr:
    print(i)
