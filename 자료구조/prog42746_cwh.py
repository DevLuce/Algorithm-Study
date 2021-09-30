## 코딩테스트 연습 > 정렬 > 가장 큰 수
from functools import cmp_to_key

def solution(numbers):
    answer = ''

    def comp(a, b):
        t1 = int(a+b)
        t2 = int(b+a)
        return (t1 > t2) - (t1 < t2)

    numbers = sorted(list(map(str, numbers)), key=cmp_to_key(comp), reverse=True)

    answer = str(int(''.join(numbers)))

    return answer

n = [3, 30, 34, 5, 9]
print(solution(n))