## 코딩테스트 연습 > 정렬 > H-Index
def solution(citations):
    answer = 0

    citations.sort()

    for idx, c in enumerate(citations):
        if len(citations) - idx <= c:
            answer = len(citations) - idx
            break

    return answer