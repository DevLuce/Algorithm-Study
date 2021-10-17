## 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 네트워크
## 완전탐색 보다는 더 효율적인 유니온-파인드로 해결
def solution(n, computers):
    parent = [i for i in range(n+1)]

    def find(a):
        if parent[a] == a:
            return a
        parent[a]=find(parent[a])
        return parent[a]

    def union(a, b):
        pa = find(a)
        pb = find(b)
        parent[pb]=pa

    for i in range(len(computers)):
        for j in range(len(computers[i])):
            if computers[i][j]==1:
                union(i+1, j+1)

    nums = set()

    for i in range(n):
        nums.add(find(i+1))

    return len(nums)