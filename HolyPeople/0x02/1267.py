n = int(input())
m = 0
y = 0

calls = input().split()

for i in calls:
    call = int(i)

    y += ((call // 30) + 1) * 10

    m += ((call // 60) + 1) * 15

if y < m:
    print('Y', y)
elif y > m:
    print("M", m)
else:
    print("Y M", y)
