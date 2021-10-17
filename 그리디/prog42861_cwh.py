## 코딩테스트 연습 > 탐욕법(Greedy) > 섬 연결하기
import heapq

def solution(n, costs):
    answer = 0

    parent = [i for i in range(n)]
    heap = []

    for c in costs:
        s, e, w = c[0], c[1], c[2]
        heapq.heappush(heap, (w, s, e))

    def find(a):
        if parent[a] == a:
            return a
        pa = parent[a]
        parent[a] = find(pa)
        return parent[a]
    
    def union(a, b):
        pa = find(a)
        pb = find(b)
        parent[pb]=pa

    while heap:
        w, s, e = heapq.heappop(heap)

        if find(s) != find(e):
            union(s, e)
            answer+=w

    return answer