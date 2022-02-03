"""
균형 잡힌 세상
문자열 입력중 괄호 쌍이 맞지 않는 것을 검사
여는 괄호가 들어 오면 스텍에 Push, 닫는 괄호가 들어 오면 스텍에 pop 하고 여는 괄호와 맞는 쌍인지 검사
스텍이 비어 있지 않으면 닫는 괄호가 없음
"""
import sys

while True:
    stack = []
    flag = False
    data = sys.stdin.readline()
    if data[0] == '.':
        break
    for i in data:
        if i == '(' or i == '[':
            stack.append(i)
        elif i == ')' or i == ']':
            if stack:
                t = stack.pop()
                if t == '(' and i == ')' or t == '[' and i == ']':
                    continue
            flag = True

    if not stack:
        flag = True

    if flag:
        print('no')
    else:
        print('yes')
