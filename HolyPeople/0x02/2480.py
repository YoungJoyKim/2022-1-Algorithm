arr = input().split()
dice = [0] * 6
for i, v in enumerate(arr):
    arr[i] = int(v)

for i in arr:
    dice[i - 1] += 1

max_val = max(dice)
max_dice = 0

for i in range(6):
    if dice[i] == max_val:
        max_dice = i + 1

reword = 0
if max_val == 3:
    reword += 10000 + max_dice * 1000
elif max_val == 2:
    reword += 1000 + max_dice * 100
else:
    reword += max_dice * 100
print(reword)
