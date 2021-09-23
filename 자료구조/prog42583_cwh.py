## 코딩테스트 연습 > 스택/큐 > 다리를 지나는 트럭
from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge = deque([0] * bridge_length)
    arrive = deque()
    curWeight = 0
    
    i=0
    while len(arrive) != len(truck_weights):
        if i<len(truck_weights) and curWeight + truck_weights[i] - bridge[0] <= weight:
            if bridge[0]>0:
                arrive.append(bridge[0])
                curWeight -= bridge[0]
            bridge.popleft()
            bridge.append(truck_weights[i])
            curWeight += truck_weights[i]
            i+=1
        else:
            if bridge[0]>0:
                arrive.append(bridge[0])
                curWeight -= bridge[0]
            bridge.popleft()
            bridge.append(0)
        answer+=1

    return answer