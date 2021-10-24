dx = [0,1,1,1,0,-1,-1, -1]
dy = [1,1,0,-1,-1,-1,0, 1]


def dfs(x, y, board):
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= len(board) or ny >= len(board[0]) or not board[nx][ny]:
            continue

        board[nx][ny] = 0
        dfs(nx, ny, board)


while True:
    w, h = map(int, input().split())
    if not w and not h:
        break
    board = []

    for i in range(h):
        board.append(list(map(int,input().split())))

    cnt = 0
    for x in range(h):
        for y in range(w):
            if board[x][y]:
                cnt += 1
                board[x][y] = 0
                dfs(x, y, board)
    print(cnt)