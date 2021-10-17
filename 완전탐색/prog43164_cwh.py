## 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 여행경로
from collections import defaultdict

isFindAns = False 

def solution(tickets):
    answer = []

    adj = defaultdict(list)
    n = 1

    for t in tickets:
        adj[t[0]].append([t[1], False])
        n += 1

    for a in adj.values():
        a.sort()

    def dfs(cur):
        global isFindAns
        answer.append(cur)
        
        # 목적지인가
        if len(answer) == n:
            isFindAns = True
            return

        # 연결된 곳 순회
        for next in adj[cur]:
            # 갈 수 있는가
            if not next[1]:
                next[1]=True
                dfs(next[0])
                if isFindAns :
                    return
                next[1]=False

        answer.pop()

    dfs("ICN")

    return answer