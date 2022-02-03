import sys

n = int(sys.stdin.readline())

for i in range(n):
    a, b = sys.stdin.readline().rstrip().split()
    alpha = [0] * 26
    for j in a:
        alpha[ord(j) - ord('a')] += 1

    for j in b:
        alpha[ord(j) - ord('a')] -= 1

    flag = True
    for j in alpha:
        if j != 0:
            flag = False
    if flag:
        print("Possible")
    else:
        print("Impossible")
