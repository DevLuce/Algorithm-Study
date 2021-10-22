from collections import Counter
import copy

r, c, k = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(3)]

time = 0
while True:
    if r-1<len(A) and c-1<len(A[0]) and A[r-1][c-1] == k:
        break
    if len(A) >= len(A[0]): # R연산
        tmpBoard = []
        maxLen = 0
        for arr in A:
            count = Counter(arr)
            count[0] = 0
            count += Counter()
            lis = sorted(count.items(), key=lambda x:(x[1], x[0]))
            tmpLine = []
            for a, b in lis:
                tmpLine.extend([a, b])
            tmpBoard.append(tmpLine)
            maxLen = max(maxLen, len(tmpLine))
        for b in tmpBoard:
            while len(b)<maxLen:
                b.append(0)
        A = copy.deepcopy(tmpBoard)
    else: # C연산
        tmpBoard = []
        maxLen = 0
        for j in range(len(A[0])):
            tmpLis = []
            for i in range(len(A)):
                tmpLis.append(A[i][j])
            count = Counter(tmpLis)
            count[0] = 0
            count += Counter()
            lis = sorted(count.items(), key=lambda x:(x[1], x[0]))
            tmpLine = []
            for a, b in lis:
                tmpLine.extend([a, b])
            tmpBoard.append(tmpLine)
            maxLen = max(maxLen, len(tmpLine))
        for b in tmpBoard:
            while len(b)<maxLen:
                b.append(0)
        rotateBoard = [[0]*len(tmpBoard) for _ in range(len(tmpBoard[0]))]
        for i in range(len(rotateBoard)):
            for j in range(len(rotateBoard[0])):
                rotateBoard[i][j] = tmpBoard[j][i]
        A = copy.deepcopy(rotateBoard)

    time+=1
    if time > 100: 
        break

if time>100 :
    print(-1)
else:
    print(time)