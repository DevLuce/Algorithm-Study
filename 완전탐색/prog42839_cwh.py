## 코딩테스트 연습 > 완전탐색 > 소수 찾기

from itertools import permutations

isPrime = [True] * 10000000
ans = set([])

def makePrime():
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, 10000000):
        if isPrime[i]:
            for j in range(i*2, 10000000, i):
                isPrime[j] = False

def solution(numbers):
    answer = 0
    
    makePrime()
    for i in range(1, len(numbers)+1):
        per = list(map(''.join, permutations(numbers, i)))
        for p in per:
            if isPrime[int(p)]:
                ans.add(int(p))
    
    answer = len(ans)
    return answer