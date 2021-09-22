## 코딩테스트 연습 > 스택/큐 > 기능개발
from collections import deque

def solution(progresses, speeds):
    answer = []
    qp = deque(progresses)
    qs = deque(speeds)
    con = False
    while qp:
        if qp[0] >= 100:
            qp.popleft()
            qs.popleft()
            if con:
                answer[-1] += 1
            else:
                answer.append(1)
            con = True
            continue
        else :
            con = False

        for i in range(len(qp)):
            if qp[i] < 100:
                qp[i] += qs[i]

    return answer