"""
쇠 막대기
막대기가 들어오면 스텍에 push
레이저가 들어오면 스택의 크기 만큼 더함!
막대기가 나가면 pop
"""
string = input()
stack = []
count = 0
for i, c in enumerate(string):
    if c == '(':
        stack.append(c)
    else:
        if string[i-1] == '(':  # laser
            stack.pop()
            count += len(stack)
        else:  # end of stick
            stack.pop()
            count += 1
print(count)
