n = int(input())
for i in range(1, 2 * n):
    print(" " * abs(n - i) + "*" * (n - abs(n - i)))