#python3 시간초과, pypy3 통과
R, C, T = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(R)]
dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]

aircleaner = 0
for i in range(R):
    if room[i][0]==-1:
        aircleaner = i
        break

while T>0:
    T-=1
    dust = [[0]*C for _ in range(R)]

    # 확산
    for i in range(R):
        for j in range(C):
            if room[i][j]>0:
                cnt = 0
                for k in range(4):
                    ny, nx = i+dy[k], j+dx[k]
                    if 0<=ny<R and 0<=nx<C and room[ny][nx]>=0:
                        cnt+=1
                        dust[ny][nx]+=room[i][j]//5
                if cnt>0:
                    room[i][j]-=(room[i][j]//5)*cnt

    # 적용
    for i in range(R):
        for j in range(C):
            room[i][j]+=dust[i][j]
    
    # 위 공기청정기 작동
    for i in range(aircleaner-1, 0, -1):
        room[i][0]=room[i-1][0]
    for j in range(C-1):
        room[0][j]=room[0][j+1]
    for i in range(aircleaner):
        room[i][C-1]=room[i+1][C-1]
    for j in range(C-1, 1, -1):
        room[aircleaner][j]=room[aircleaner][j-1]
    room[aircleaner][1]=0

    # 아래 공기청정기 작동
    for i in range(aircleaner+2, R-1):
        room[i][0]=room[i+1][0]
    for j in range(C-1):
        room[R-1][j]=room[R-1][j+1]
    for i in range(R-1, aircleaner+1, -1):
        room[i][C-1]=room[i-1][C-1]
    for j in range(C-1, 1, -1):
        room[aircleaner+1][j]=room[aircleaner+1][j-1]
    room[aircleaner+1][1] = 0

ans = 0
for i in range(R):
    for j in range(C):
        if room[i][j]>0:
            ans+=room[i][j]

print(ans)