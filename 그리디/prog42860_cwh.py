## 코딩테스트 연습 > 탐욕법(Greedy) > 조이스틱

def solution(name):
    answer = 0
    min_move = len(name) - 1
    next = 0
    
    for i, n in enumerate(name):
        answer += min(ord(n)-ord('A'), ord('Z')-ord(n)+1)
        
        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
        
        # 돌아가는 경우
        min_move = min(min_move, i + i + len(name) - next)
    answer += min_move
    return answer