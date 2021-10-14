"""
괄호의 값 (실2 구현) : https://www.acmicpc.net/problem/2504

전체 시간 : 1시간 20분

1. 문제 이해, 추상화) 5분 이내
2. 로직 플로우 설계) 1시간 전후
3. 수도 코드 작성 및 실제 코드 작성) 20분
4. 코드 구현 에러처리) 10 ~ 15분
"""

from collections import defaultdict

str = input()
temp = defaultdict(int)
stack = []


for s in str:
    n = -1
    if s == '(' or s == '[':
        stack.append(s)
        continue
    if not stack or not ((stack[-1] == '(' and s == ')') or (stack[-1] == '[' and s == ']')):
        print(0)
        exit(0)

    top = stack.pop()

    if top == '(':
        n = 2
    else:
        n = 3

    depth = len(stack)
    if temp[depth + 1]:
        temp[depth] += (temp[depth + 1] * n)
        temp[depth + 1] = 0
    else:
        temp[depth] += n
print(temp[0])


