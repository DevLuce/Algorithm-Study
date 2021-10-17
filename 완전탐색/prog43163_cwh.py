## 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 단어 변환
from collections import deque

def solution(begin, target, words):
    answer = 0

    if target not in words:
        return 0

    def diff(str1, str2):
        cnt = 0
        for i in range(len(str1)):
            if str1[i]!=str2[i]:
                cnt+=1
        return cnt

    q = deque()
    q.append((begin, 0))
    visit = [False] * (len(words))

    while q:
        # 큐에서 꺼낸다
        cur, cnt = q.popleft()

        # 목적지인가
        if cur == target:
            answer = cnt

        # 연결된 곳 순회
        for i, w in enumerate(words):
            # 갈 수 있는가
            if diff(cur, w)==1 and not visit[i]:
                visit[i] = True
                # 큐에 넣는다
                q.append((w, cnt+1))

    return answer