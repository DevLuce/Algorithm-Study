from collections import deque

gear=[deque(list(map(int, input()))) for _ in range(4)] # 시계 방향

K = int(input())

def left_move_gear(n, d):
    if n == 1:
        if d==1:
            tmp = gear[n-1].pop()
            gear[n-1].appendleft(tmp)
        else:
            tmp = gear[n-1].popleft()
            gear[n-1].append(tmp)
    else:
        if gear[n-1][6] != gear[n-2][2]:
            left_move_gear(n-1, d*(-1))
        if d==1:
            tmp = gear[n-1].pop()
            gear[n-1].appendleft(tmp)
        else:
            tmp = gear[n-1].popleft()
            gear[n-1].append(tmp)

def right_move_gear(n, d):
    if n == 4:
        if d==1:
            tmp = gear[n-1].pop()
            gear[n-1].appendleft(tmp)
        else:
            tmp = gear[n-1].popleft()
            gear[n-1].append(tmp)
    else:
        if gear[n-1][2] != gear[n][6]:
            right_move_gear(n+1, d*(-1))
        if d==1:
            tmp = gear[n-1].pop()
            gear[n-1].appendleft(tmp)
        else:
            tmp = gear[n-1].popleft()
            gear[n-1].append(tmp)

for _ in range(K):
    num, dir = map(int, input().split())
    if num==1:
        right_move_gear(num, dir)
    elif num==4:
        left_move_gear(num, dir)
    else:
        tmpNum1, tmpNum2 = gear[num-1][2], gear[num][6]
        left_move_gear(num, dir)
        if tmpNum1 != tmpNum2:
            right_move_gear(num+1, dir*(-1))

ans = 0
times = 1
for g in gear:
    ans+=g[0]*times
    times*=2

print(ans)