## 코딩테스트 연습 > 탐욕법(Greedy) > 큰 수 만들기

def solution(number, k):
    stack = []
    
    for n in number:
        while stack and stack[-1] < n and k > 0:
            k -= 1
            stack.pop()
        stack.append(n)
    
    print(stack)
    return ''.join(stack[:len(stack)-k])