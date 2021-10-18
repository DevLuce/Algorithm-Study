## 코딩테스트 연습 > 그래프 > 순위
def solution(n, results):
    answer = 0
    dp=[[-1]*(n+1) for _ in range(n+1)]

    for i in range(n+1):
        for j in range(n+1):
            if i==j:
                dp[i][j]=0

    for r in results:
        a, b = r[0], r[1]
        dp[a][b] = 1 # 승리
        dp[b][a] = 2 # 패배

    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if dp[i][k]==1 and dp[k][j]==1:
                    dp[i][j]=1
                    dp[j][i]=2
                elif dp[i][k]==2 and dp[k][j]==2:
                    dp[i][j]==2
                    dp[j][i]==1

    for i in range(1, n+1):
        if -1 not in dp[i][1:]:
            answer+=1     

    return answer