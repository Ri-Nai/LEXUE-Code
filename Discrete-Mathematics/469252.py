def get_inv(func):
    id = int(func[-1])
    if id <= 3 or id == 6:
        return "f" + str(id)
    else:
        return "f" + str(9 - id)
print get_inv(raw_input())
"""
f1(x) = x f1 ^ -1 (x) = x
f2(x) = 1 - x, f2 ^ -1 (x) = 1 - x
...
"""

