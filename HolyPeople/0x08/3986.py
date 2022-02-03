"""좋은 단어
AB가 서로 교차 하지 않는 문장의 개수
"""
N = int(input())
count = 0
for i in range(N):
    stack = []
    word = input()
    for c in word:
        if stack and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    if not stack:
        count += 1
print(count)
