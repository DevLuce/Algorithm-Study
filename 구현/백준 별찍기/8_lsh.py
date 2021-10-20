N = int(input())

for n in range(1, N * 2):
    i = abs(N - n)
    print((N - i) * '*' + ' ' * (2 * N - 2 * (N - i)) + (N - i) * '*')
