"""
한 줄로 서기 (실2 구현) : https://www.acmicpc.net/problem/1138

전체 시간 : 49분

1. 문제 이해) 2분 40
2. 추상화) 7분 20
3. 로직 플로우 설계) 9분
4. 수도 코드 작성 및 실제 코드 작성) 17분
5. 코드 구현 에러처리) 13분
"""

N = int(input())
nums = list(map(int, input().split()))
ret = [-1 for _ in range(N)]

for height, num in enumerate(nums, start=1):
    idx = 0
    while num:
        if ret[idx] == -1:
            num -= 1
        idx += 1

    while ret[idx] != -1:
        idx += 1
    ret[idx] = height


print(*ret)
