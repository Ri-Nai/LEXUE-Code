n = int(raw_input())
G = [
    map(int, raw_input().split())
    for _ in range(n)
]

color = [0] * n
def bfs(S):
    Q = [S]
    color[S] = 1
    while Q:
        u = Q.pop(0)
        for v in range(n):
            if G[u][v]:
                if color[v] == 0:
                    color[v] = -color[u]
                    Q.append(v)
                elif color[v] == color[u]:
                    return False
    return True
def is_bipartite():
    for i in range(n):
        if color[i] == 0:
            if not bfs(i):
                return False
    return True
if is_bipartite():
    print 'yes'
else:
    print 'no'
