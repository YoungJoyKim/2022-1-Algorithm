alpha = [0] * 26
s = input()
for i in s:
    alpha[ord(i) - ord('a')] += 1

for i in alpha:
    print(i, end=' ')
