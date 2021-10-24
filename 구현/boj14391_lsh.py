def find_next():
    for i in range(N):
        for j in range(M):
            if not visit[i][j]:
                return i, j
    return -1, -1


def recur():
    x, y = find_next()

    if x == -1:
        return 0

    ret = 0
    cur_sum = 0
    end_point = 0
    for idx in range(N - x):
        if visit[x + idx][y]:
            end_point = x + idx
            break
        cur_sum = cur_sum * 10 + board[x + idx][y]
        visit[x + idx][y] = 1
        cand = recur() + cur_sum
        ret = max(ret, cand)

    if not end_point:
        end_point = N

    for idx in range(x, end_point):
        visit[idx][y] = 0

    cur_sum = 0
    end_point = 0
    for idx in range(M - y):
        if visit[x][y + idx]:
            end_point = y + idx
            break

        cur_sum = cur_sum * 10 + board[x][y + idx]
        visit[x][y + idx] = 1
        cand = recur() + cur_sum
        ret = max(ret, cand)

    if not end_point:
        end_point = M

    for idx in range(y, end_point):
        visit[x][idx] = 0


    return ret


N, M = tuple(map(int,input().split()))
board = []
visit = []
for i in range(N):
    board.append([int(s) for s in input()])
    visit.append([0] * M)


print(recur())
