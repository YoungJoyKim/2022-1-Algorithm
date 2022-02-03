yut_string = "EABCD"
for i in range(3):
    yut = input().split()
    count = 0
    for i in yut:
        if i == '0':
            count += 1
    print(yut_string[count])
