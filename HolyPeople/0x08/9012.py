"""
괄호 Valid Parenthesis String
여는 괄호와 닫는 괄호의 쌍이 올바른 문장을 판별
"""
N = int(input())
for i in range(N):
    string = input()
    stack = []
    is_valid = True
    for c in string:
        if c == '(':
            stack.append(c)
        elif c == ')':
            if not stack or stack[-1] != '(':
                is_valid = False
                break
            stack.pop()
    if stack:
        is_valid = False

    print("YES" if is_valid else "NO")
