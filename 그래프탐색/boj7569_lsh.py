from collections import deque


def is_full_riped():
    max_cnt = -1
    for h in range(H):
        for i in range(N):
            for j in range(M):
                max_cnt = max(max_cnt, board[h][i][j])
                if board[h][i][j] == 0:
                    return 0
    return max_cnt


def bfs():
    q = deque()

    if is_full_riped():
        return 0

    for h in range(H):
        for i in range(N):
            for j in range(M):
                if board[h][i][j] == 1:
                    q.append((h, i, j, 1))

    while q:
        h, x, y, cnt = q.popleft()


        ret = is_full_riped()
        if ret:
            return ret

        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nh = h + dh[i]

            if nx < 0 or ny < 0 or nh < 0 or nx >= N or ny >= M or nh >= H or board[nh][nx][ny] != 0:
                continue

            board[nh][nx][ny] = cnt
            q.append((nh, nx, ny, cnt + 1))

    if not is_full_riped():
        return -1


dx = [-1,1,0,0,0,0]
dy = [0,0,-1,1,0,0]
dh = [0,0,0,0,-1,1]

board = []
M, N, H = map(int, input().split())

for _ in range(H):
    board.append([list(map(int, input().split())) for _ in range(N)])

print(bfs())
