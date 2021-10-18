from collections import deque

op, cor = deque(), deque()

N = int(input())
K = int(input())

board = [[0]*N for _ in range(N)]
for _ in range(K):
    r, c = map(int, input().split())
    board[r-1][c-1]=2

L = int(input())
for _ in range(L):
    t, o = input().split()
    op.append((int(t), o))

cor.append((0, 0))
dir = [0, 1]
seq = [[0,1], [1,0], [0,-1], [-1,0]]
s = 0
sec = 0

while True:
    r, c = cor[0]
    ny, nx = r+dir[0], c+dir[1]
    sec +=1

    if ny<0 or N<=ny or nx<0 or N<=nx or board[ny][nx]==1:
        break
    
    if board[ny][nx]==0:
        ty, tx = cor.pop()
        board[ty][tx]=0
    board[ny][nx]=1
    cor.appendleft((ny,nx))

    if op and op[0][0] == sec:
        o = op.popleft()
        if o[1] == 'D':
            s+=1
            if s==4:
                s=0
        else:
            s-=1
            if s==-1:
                s=3
        dir=seq[s]

print(sec)