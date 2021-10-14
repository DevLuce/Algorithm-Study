"""
경비원 (실1, 구현) : https://www.acmicpc.net/problem/2564


총 걸린 시간 : 48분

1. 문제 이해) 3분 00초
2. 추상화 )  2분 30초
3. 로직 플로) 10분
4. 수도 코드 작성, 구현) 25분
5. 로직 플로 다시 짜기) 4분
6. 다시 수도 코드 작성 및 구현, 제출) 4분
"""


row, col = list(map(int, input().split()))
n = int(input())
stores = []

for _ in range(n + 1):
    d, loc = list(map(int, input().split()))
    x = -1

    if d == 1:
        x = loc
    elif d == 2:
        x = row * 2 + col - loc
    elif d == 3:
        x = 2 * row + 2 * col - loc
    elif d == 4:
        x = row + loc
    stores.append(x)

don_gun = stores.pop()
ret = 0
for s in stores:
    ret += min(abs(don_gun - s), row * 2 + col * 2 - abs(don_gun - s))
print(ret)
