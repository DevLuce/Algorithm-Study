# 스택/큐 > 주식가격

def solution(prices):
    answer = [-1] * len(prices)

    stack = []

    for idx in range(len(prices)):
        if not stack or prices[stack[-1]] <= prices[idx]:
            stack.append(idx)
            continue

        while stack and prices[stack[-1]] > prices[idx]:
            top_idx = stack.pop()
            answer[top_idx] = idx - top_idx
        stack.append(idx)

    for idx in stack:
        answer[idx] = len(answer) - 1 - idx

    return answer