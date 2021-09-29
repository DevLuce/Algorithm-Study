## 코딩테스트 연습 > 힙 > 더 맵게
import heapq

def solution(scoville, K):
    answer = 0

    heapq.heapify(scoville)

    while scoville:
        if scoville[0] >= K:
            break
        else:
            first = heapq.heappop(scoville)
            if len(scoville) == 0: return -1
            second = heapq.heappop(scoville)
            heapq.heappush(scoville, first+second*2)
            answer += 1

    return answer