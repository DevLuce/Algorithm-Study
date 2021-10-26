"""
영역 구하기 (실1, 그래프 탐색) : https://www.acmicpc.net/problem/2583
1. 읽기 : 2분 30초
2. 추상화 : 2분
3. 구현 및 제출 : 20분
4. 디버깅 : 20분 이상

아직까지 잔실수가 너무 많다.
계속 그래프 탐색 문제를 풀면서 연습을 통해 실수 없이 코딩하고, 구현 시간을 줄여나가도록 하자.
"""

from collections import deque


def fill_board(locs):
    for loc in locs:
        l_x, l_y, r_x, r_y = loc[1], loc[0], loc[3] - 1, loc[2] - 1  # 오류난 지점.

        for x in range(l_x, r_x + 1):  # 오류난 지점.
            for y in range(l_y, r_y + 1):
                board[x][y] = 1


def bfs(x, y):
    dq = deque()
    dq.append((x, y))
    board[x][y] = 1
    ret = 1

    while dq:
        cx, cy = dq.popleft()

        for i in range(4):
                nx, ny = cx + dx[i], cy + dy[i]

                if not (0 <= nx < N and 0 <= ny < M and board[nx][ny] == 0):
                    continue
                board[nx][ny] = 1
                dq.append((nx, ny))
                ret += 1  # 그냥 ret를 1씩 증가 시켜주기만 하면 답이 바로 나오는데... 한창 돌아갔음
    return ret


dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
N, M, K = map(int, input().split())
locs = []
board = [[0] * M for _ in range(N)]

for _ in range(K):
    locs.append(list(map(int, input().split())))

fill_board(locs)  # 까먹고 fill_board 함수 자체를 안불러줬음


cnt = 0
rets = []
for x in range(N):
    for y in range(M):
        if not board[x][y]:
            cnt += 1
            rets.append(bfs(x, y))


print(cnt)
print(*sorted(rets))
