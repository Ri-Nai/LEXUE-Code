import sys
input = sys.stdin.readline
floyd = []
while True:
    s = input().strip()
    if not s:
        break
    floyd.append(list(map(int, s.split())))
n = len(floyd)
for k in range(n):
    for i in range(n):
        for j in range(n):
            floyd[i][j] |= floyd[i][k] & floyd[k][j]
for s in floyd:
    print(' '.join(map(str, s)))

