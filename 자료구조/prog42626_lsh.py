import heapq


def solution(scoville, K):
    heapq.heapify(scoville)
    ans = 0

    while scoville[0] < K:
        if len(scoville) <= 1: return -1

        heapq.heappush(scoville, heapq.heappop(scoville) + heapq.heappop(scoville) * 2)
        ans += 1

    return ans
