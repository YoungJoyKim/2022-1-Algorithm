arr = [0] * 9
n = input()
for i in n:
    t = ord(i) - 48
    if t == 9:
        t = 6
    arr[t] += 1

arr[6] = arr[6] // 2 + arr[6] % 2

print(max(arr))
