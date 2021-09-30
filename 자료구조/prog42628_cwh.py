## 코딩테스트 연습 > 힙 > 이중우선순위큐
import heapq

def solution(operations):
    answer = []

    maxHeap = []
    minHeap = []

    for o in operations:
        op, n = o.split()
        n = int(n)

        if op == 'I':
            heapq.heappush(maxHeap, (-n, n))
            heapq.heappush(minHeap, n)

        else:
            if n == 1:
                if maxHeap:
                    _, num = heapq.heappop(maxHeap)
                    minHeap.remove(num)
            else:
                if minHeap:
                    num = heapq.heappop(minHeap)
                    maxHeap.remove((-num,num))
    
    if maxHeap:
        answer.append(maxHeap[0][1])
        answer.append(minHeap[0])
    else:
        answer += [0, 0]

    return answer