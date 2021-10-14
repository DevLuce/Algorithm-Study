"""
별찍기 - 22 (실버2, 구현) : https://www.acmicpc.net/problem/10997

총 걸린 시간: 1시간 10분

1. 읽기 & 추상화) 10초
2. 로직 플로우 설계) 10분
3. 구현) 1시간

"""


def fill_board(depth):
    start = 2 * (n - depth)
    last = start + 4 * depth

    for x in range(start, last - 1):
        if start != 0 and x == start:
            board[x][last - 3] = '*'

        for y in range(start, last - 3):
            if x % 2 == 1 and x == start + 1 and y == last - 4:
                continue

            if x == start or x == last - 2 or y == start or y == last - 4:
                board[x][y] = '*'
    if depth == 1:
        board[start + 1][start] = '*'

n = int(input())
board = []

if n == 1:
    print("*", end='')
    exit(0)
else:
    for _ in range(4 * n - 1):
        board.append([' ' for _ in range(4 * n - 3)])

for depth in range(1, n + 1):
    fill_board(depth)

ret = []

for b in board:
    str = ''.join(b).strip()
    ret.append(str)

for _ in ret:
    print(_)