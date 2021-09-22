## 코딩테스트 연습 > 스택/큐 > 프린터
from collections import deque 

def solution(priorities, location):
    answer = 0
    
    idx = [ i for i in range(len(priorities))]

    q = deque(priorities)
    qIdx = deque(idx)
    cnt = 0

    while True:
        maxNum = max(q)
        if q[0] == maxNum:
            cnt += 1
            if qIdx[0] == location:
                answer = cnt
                break
            else:
                q.popleft()
                qIdx.popleft()
        else:
            tmpNum = q.popleft()
            tmpIdx = qIdx.popleft()
            q.append(tmpNum)
            qIdx.append(tmpIdx)

    return answer