# python3 시간초과, pypy3 통과
import copy

N, M = map(int, input().split())
loc = [list(map(int, input().split())) for _ in range(N)]
direction = [[], [[0], [1], [2], [3]], [[0, 2], [1, 3]], [[0, 1], [1, 2], [2, 3], [3, 0]], [[3, 0, 1], [0, 1, 2], [1, 2, 3], [2, 3, 0]], [[0, 1, 2, 3]]]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

camCnt = 0
q = []
ans = N*M

for i in range(N):
    for j in range(M):
        if loc[i][j] != 0 and loc[i][j] != 6:
            camCnt+=1
            q.append((i, j, loc[i][j]))

def watch(y, x, dir, tmp):
    for d in dir:
        ny = y
        nx = x
        while True:
            ny+=dy[d]
            nx+=dx[d]
            if 0<=ny<N and 0<=nx<M and tmp[ny][nx]!=6:
                if tmp[ny][nx] == 0:
                    tmp[ny][nx] = '#'
            else:
                break

def dfs(off, cnt):
    global ans

    tmp = copy.deepcopy(off)
    if cnt == camCnt:
        tmpAns = 0
        for t in tmp:
            tmpAns += t.count(0)
        ans = min(ans, tmpAns)
        return

    y, x, cam = q[cnt]
    for dir in direction[cam]:
        watch(y, x, dir, tmp)
        dfs(tmp, cnt+1)
        tmp = copy.deepcopy(off)

dfs(loc, 0)
print(ans)