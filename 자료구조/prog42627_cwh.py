## 코딩테스트 연습 > 힙 > 디스크 컨트롤러
import heapq

def solution(jobs):
    answer = 0

    jobs = sorted(jobs)
    curIdx = 0
    heap = []
    working = 0
    time = 0

    while True:
        if curIdx >= len(jobs) and not heap:
            break

        # 요청
        while curIdx < len(jobs) and time == jobs[curIdx][0]:
            heapq.heappush(heap, (jobs[curIdx][1], jobs[curIdx][0]))
            curIdx += 1
        
        # 작업 진행
        if working == 0 and heap:
            t, r = heapq.heappop(heap)
            working = t
            answer += (time-r) + t
            working -= 1
        elif working > 0:
            working -= 1

        time += 1

    return answer // len(jobs)