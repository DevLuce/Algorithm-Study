## 코딩테스트 연습 > 해시 > 베스트앨범
import operator

def solution(genres, plays):
    answer = []
    pg = []
    gen = {}

    for i, g in enumerate(genres):
        if g not in gen:
            gen[g] = plays[i]
        else:
            gen[g] += plays[i]
        pg.append([plays[i], g, i])

    sgen = sorted(gen.items(), key=operator.itemgetter(1), reverse=True)
    spg = sorted(pg, key=lambda x : (x[0], -x[2]), reverse=True)

    for g in sgen:
        cnt = 2
        for p in spg:
            if p[1]==g[0]:
                answer.append(p[2])
                cnt -= 1
            if cnt == 0:
                break

    return answer