## 코딩테스트 연습 > 그래프 > 가장 먼 노드
from collections import defaultdict, deque

def solution(n, edge):
    answer = 0

    adj = defaultdict(list)
    visit = defaultdict(bool)

    for e in edge:
        adj[e[0]].append(e[1])
        adj[e[1]].append(e[0])

    q = deque()
    q.append((1,0))
    visit[1] = True

    maxCnt = 0

    while q:
        cur, cnt = q.popleft()

        if maxCnt == cnt:
            answer+=1
        elif maxCnt < cnt:
            maxCnt = cnt
            answer = 1

        for next in adj[cur]:
            if not visit[next]:
                visit[next]=True
                q.append((next, cnt+1))

    return answer