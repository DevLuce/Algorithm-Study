## 코딩테스트 연습 > 탐욕법(Greedy) > 구명보트

def solution(people, limit):
    answer = 0
    
    people.sort(reverse=True)
    
    i=0
    j=len(people)-1
    
    while i<=j:
        if people[i]+people[j] <= limit:
            j-=1
        i+=1
        answer+=1
    
    return answer