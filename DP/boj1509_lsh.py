import math, sys
# sys.setrecursionlimit(10000)


def is_palindrome(s):
    left, right = 0, len(s) - 1
    while left < right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    return True

def recur(left, right):
    if cache[left][right] != -1:
        return cache[left][right]
    if left >= right:
        return 1
    if left + 1 == right:
        if is_palindrome(s[left:right + 1]):
            return 1
        else:
            return 2

    if is_palindrome(s[left:right + 1]):
        cache[left][right] = 1
        return cache[left][right]

    ret = math.inf
    for middle in range(left + 1, right + 1):
        ret = min(ret, recur(left, middle - 1) + recur(middle, right))
    cache[left][right] = ret

    return cache[left][right]



s = input()
cache = [[-1] * (len(s) + 1) for _ in range(len(s) + 1)]
print(recur(0, len(s) - 1))