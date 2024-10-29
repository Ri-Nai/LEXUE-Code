has = set()
import sys
sys.stdout = open('output.out', 'w')
for i in range(1, 20):
    res = []
    first = 0
    for j in range(1, 114514):
        if j not in has:
            first = j
            break
    second = first * 2 - i + 1
    res += [first, second]
    while len(res) < 20:
        res.append(res[-1] + res[-2])
    has.update(res)
    print(' '.join(map(lambda x : "{:<4d}".format(x), res[:10])))
