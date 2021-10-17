## 코딩테스트 연습 > 탐욕법(Greedy) > 단속카메라

def solution(routes):
    answer = 0

    routes.sort(key=lambda x:x[1])

    curCam = -30001
    for r in routes:
        if curCam < r[0]:
            answer+=1
            curCam = r[1]

    return answer