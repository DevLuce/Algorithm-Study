import bisect

n = int(input())

a, b, c, d = [], [], [], []
for _ in range(n):
    q,w,e,r = map(int, input().split())
    a.append(q)
    b.append(w)
    c.append(e)
    d.append(r)


ab = []
cd = []

for i in range(n):
    for j in range(n):
        ab.append(a[i] + b[j])
        cd.append(c[i] + d[j])

cnt = 0
ab.sort()
cd.sort()

hi = len(ab)

for i in range(len(ab)):
    num = ab[i]
    left = bisect.bisect_left(cd, -num)
    right = bisect.bisect_right(cd, -num)

    if left == hi or cd[left] != -num:
        continue
    cnt += (right - left)
    hi = right
print(cnt)

