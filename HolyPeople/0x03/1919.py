import sys

a = sys.stdin.readline().rstrip()
b = sys.stdin.readline().rstrip()

alpha = [0] * 26
bet = [0] * 26

for i in a:
    alpha[ord(i) - ord('a')] += 1
for i in b:
    bet[ord(i) - ord('a')] += 1

result = 0
for i in range(26):
    result += abs(alpha[i] - bet[i])

print(result)
