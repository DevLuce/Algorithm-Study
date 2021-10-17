## 코딩테스트 연습 > 완전탐색 > 카펫

def solution(brown, yellow):
    t = brown//2
    y = t//2
    
    while True:
        x = t-y 
        if (x-1)*(y-1) == yellow:
            break
        y -= 1
    
    return [x+1, y+1]