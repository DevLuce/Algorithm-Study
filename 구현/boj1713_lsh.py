"""
후보 추천하기 (실2 구현): https://www.acmicpc.net/problem/1713

전체 시간 : 39분
1. 문제 이해) 3분
2. 추상화) 1분
3. 로직 플로우 설계) 5분
4. 수도 코드 작성) 19분
5. 코드 작성 및 제출) 6분
6. 에러 해결) 5분
"""


n = int(input())
cand_num = int(input())
cands = list(map(int, input().split()))
photos = []
time = 0

for cand in cands:
    time -= 1
    cnt = -1
    st_ids = [p[2] for p in photos]

    if cand in st_ids:
        cand_idx = st_ids.index(cand)
        cnt = photos[cand_idx][0] - 1
        photos[cand_idx] = (cnt, photos[cand_idx][1], cand)

        photos.sort(key=lambda x: (x[0], x[1], x[2]))
        continue

    if n == len(photos):
        photos.pop()

    photos.append((cnt, time, cand))
    photos.sort(key=lambda x: (x[0], x[1], x[2]))

ret = [p[2] for p in photos]

print(*sorted(ret))
