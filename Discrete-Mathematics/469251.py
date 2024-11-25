def get_stage(n):
    if n == 0:
        return 0
    res = 1
    while (res * n) % 18 != 0:
        res += 1
    return res
print(get_stage(int(input())))

