import sys

input = sys.stdin.readline

n = int(input())
solution = list(map(int, input().rstrip().split(" ")))

start = 0
end = n - 1
min_p_value = float("inf")
while start < end:
    forward = solution[start]
    backward = solution[end]
    p_value = forward + backward

    if abs(min_p_value) > abs(p_value):
        min_p_value = p_value
        selected = (forward, backward)
    if abs(forward) > abs(backward):
        start += 1
    elif abs(forward) < abs(backward):
        end -= 1
    else:
        selected = (forward, backward)
        break

print(*selected)
