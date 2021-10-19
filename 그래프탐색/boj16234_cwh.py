## python3 시간초과, pypy3 통과
from collections import deque

N, L, R = map(int, input().split())

country = [list(map(int, input().split())) for _ in range(N)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

isAgain = True
days = -1
while isAgain:
    aveList = deque()
    visit = [[False]*N for _ in range(N)]
    isAgain = False
    days += 1

    for i in range(N):
        for j in range(N):
            tsum = 0
            cnt = 0
            if not visit[i][j]:
                visit[i][j] = True
                q = deque()
                q.append((i,j))

                while q:
                    r, c = q.popleft()
                    tsum += country[r][c]
                    cnt +=1

                    for k in range(4):
                        ny, nx = r+dy[k], c+dx[k]
                        if 0<=ny<N and 0<=nx<N and not visit[ny][nx] and L <= abs(country[r][c]-country[ny][nx]) <= R:
                            visit[ny][nx]=True
                            q.append((ny, nx))
            if cnt > 1:
                aveList.append(tsum//cnt)
                isAgain = True
            else:
                aveList.append(country[i][j])

    replica = [[0]*N for _ in range(N)]
    visit = [[False]*N for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if aveList:
                ave = aveList.popleft()
            if not visit[i][j]:
                visit[i][j] = True
                q = deque()
                q.append((i,j))

                while q:
                    r, c = q.popleft()
                    replica[r][c] = ave

                    for k in range(4):
                        ny, nx = r+dy[k], c+dx[k]
                        if 0<=ny<N and 0<=nx<N and not visit[ny][nx] and L <= abs(country[r][c]-country[ny][nx]) <= R:
                            visit[ny][nx]=True
                            q.append((ny, nx))
    
    country = replica

print(days)