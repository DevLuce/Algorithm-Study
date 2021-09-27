from collections import deque


# 다리를 지나는 트럭 (https://programmers.co.kr/learn/courses/30/lessons/42583)
def solution(bridge_length, max_weight, truck_weights):
    trucks = deque(truck_weights)
    bridge = deque([0] * bridge_length)

    arrivals = 0
    time = 0
    current_weight = 0

    while arrivals < len(truck_weights):
        time += 1
        arrived = bridge.pop()
        current_weight -= arrived
        if arrived != 0:
            arrivals += 1

        if trucks and trucks[0] + current_weight <= max_weight:
            next_truck = trucks.popleft()
            bridge.appendleft(next_truck)
            current_weight += next_truck
        else:
            bridge.appendleft(0)

    return time
