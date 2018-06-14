line = input().split()
stack = []
ans = 0
for elem in line:
    if elem in ['+', '-', '*']:

        ele2 = int(stack.pop())
        ele1 = int(stack.pop())
        if elem == '+':
            tmp = ele1 + ele2
        if elem == '-':
            tmp = ele1 - ele2
        if elem == '*':
            tmp = ele1 * ele2
        stack.append(tmp)
    else:
        stack.append(elem)
print(stack[0])
