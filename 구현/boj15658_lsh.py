"""
연산자 끼워넣기2 (실버 2, 구현) : https://www.acmicpc.net/problem/15658


총 걸린 시간 : 46분

1. 문제 이해 : 2분 36초
2. 추상화 : 2분
3. 로직 플로 설계 : 9분
4. 수도코드 및 코드 구현 : 29분
5. 에러 확인 및 수정, 재제출 : 4분
"""


def choose(depth, selected):
    if len(selected) == depth:

        cases.append([i for i in selected])
        return

    for i in range(4):
        if opers[i] == 0:
            continue

        opers[i] -= 1
        selected.append(i)
        choose(depth, selected)
        opers[i] += 1
        selected.pop()


cases = []
N = int(input())
nums = list(map(int, input().split()))
opers = list(map(int, input().split()))

choose(N - 1, [])

case_num = len(cases)

ret = []

for case in cases:
    stack = [c for c in nums][::-1]
    oper_stack = [c for c in case]

    while oper_stack:
        s_1 = stack.pop()
        s_2 = stack.pop()
        op = oper_stack.pop()

        if op == 0:
            stack.append(s_1 + s_2)
        elif op == 1:
            stack.append(s_1 - s_2)
        elif op == 2:
            stack.append(s_1 * s_2)
        elif op == 3:
            if s_1 < 0:
                stack.append(-(-s_1 // s_2))
            else:
                stack.append(s_1 // s_2)

    ret.append(stack[0])

ret.sort()
print(ret[-1])
print(ret[0])
