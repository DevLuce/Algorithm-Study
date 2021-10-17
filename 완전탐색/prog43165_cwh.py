## 코딩테스트 연습 > 깊이/너비 우선 탐색(DFS/BFS) > 타겟 넘버
answer = 0

def solution(numbers, target):
    global answer
    
    def dfs(cnt, n):
        global answer
        # 목적지인가
        if cnt == len(numbers) and n == target:
            answer+=1
            return
        
        # 연결된 곳 순회
        # 갈 수 있는가
        if cnt<len(numbers):
            dfs(cnt+1, n+numbers[cnt])
            dfs(cnt+1, n-numbers[cnt])
            
    dfs(0, 0)
    
    return answer