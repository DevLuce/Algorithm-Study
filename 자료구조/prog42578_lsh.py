from collections import defaultdict


def solution(clothes):
    closet = defaultdict(list)
    answer = 1

    for cloth in clothes:
        closet[cloth[1]].append(cloth[0])


    for val in closet.values():
        answer *= len(val) + 1

    return answer - 1