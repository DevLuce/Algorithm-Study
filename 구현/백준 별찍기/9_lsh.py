N = int(input())

for i in range(1, 2 * N):
    i = abs(N - i)
    print(' ' * (N - i - 1), end='')
    print('*' * (i * 2 + 1))