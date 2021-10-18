## 코딩테스트 연습 > 이분탐색 > 입국심사

def solution(n, times):
    answer = 0
    times.sort
    minNum, maxNum = 0, times[-1]*n
    
    while minNum<=maxNum:
        mid = (minNum+maxNum)//2
        
        tsum=0
        for t in times:
            tsum += mid//t
            
        if tsum == n:
            answer = mid
            maxNum = mid-1
        elif tsum > n:
            maxNum = mid-1
        else:
            minNum = mid+1
            
        if minNum > maxNum:
            answer = minNum
    
    return answer