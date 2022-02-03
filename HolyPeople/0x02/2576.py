arr = []
for i in range(7):
    t = int(input())
    if t % 2 != 0:
        arr.append(t)

if arr:
    print(sum(arr))
    print(min(arr))
else:
    print(-1)
