n = int(raw_input())
G = [
    [
        (int(i == j) | int(x))
        for j, x in enumerate(raw_input().split())
    ]
    for i in range(n)
]

def get_floyd(G):
    floyd = G
    for k in range(n):
        floyd = [
            [
                floyd[i][j] | (floyd[i][k] & floyd[k][j])
                for j in range(n)
            ]
            for i in range(n)
        ]
    return floyd

def get_ans(floyd):
    if any(floyd[i][j] == 0 and floyd[j][i] == 0 for i in range(n) for j in range(n)):
        return 'C'
    if any(floyd[i][j] + floyd[j][i] == 1 for i in range(n) for j in range(n)):
        return 'B'
    if all(floyd[i][j] for i in range(n) for j in range(n)):
        return 'A'

print get_ans(get_floyd(G))
