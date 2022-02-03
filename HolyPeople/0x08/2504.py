"""
괄호의 값
() 혹은 []를 만나면 s +.
중첩된 소괄호/대괄호의 *  n . """

string = input()
stack = []
s = 0
n = 1
is_valid = True
for i, c in enumerate(string):
    if c == '(':
        n *= 2
        stack.append(c)
    elif c == '[':
        n *= 3
        stack.append(c)
    elif c == ')':
        if not stack or stack[-1] != '(':
            is_valid = False
            break
        if string[i - 1] == '(':
            s += n
        stack.pop()
        n //= 2
    else:  # c == ']'
        if not stack or stack[-1] != '[':
            is_valid = False
            break
        if string[i - 1] == '[':
            s += n
        stack.pop()
        n //= 3
if stack or not is_valid:
    print(0)
else:
    print(s)
