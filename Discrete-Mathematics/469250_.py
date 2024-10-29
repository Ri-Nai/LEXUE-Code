element = raw_input().split(',')
n = len(element)
id = dict([(element[i], i) for i in range(n)])
inDegree = [0] * n
outDegree = [0] * n
edges = raw_input().split(">,<")
for edge in edges:
    u, v = map(lambda x: id[x], edge.replace("<", "").replace(">", "").split(","))
    inDegree[v] += 1
    outDegree[u] += 1
minres = sorted(filter(lambda x: inDegree[id[x]] == 0, element))
maxres = sorted(filter(lambda x: outDegree[id[x]] == 0, element))
print ",".join(minres)
print ",".join(maxres)
