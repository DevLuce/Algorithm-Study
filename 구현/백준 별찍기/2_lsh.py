# 별 찍기-2: https://www.acmicpc.net/problem/2439

n = int(input())

[print(f"{(n - i - 1) * ' '}{(i + 1) * '*'}") for i in range(n)]
