# coding: utf-8
expr = input()
chars = []
mn = 'z'
mx = 'a'
for i in expr:
    if i.isalpha():
        mx = max(mx, i)
        mn = min(mn, i)
chars = [chr(i) for i in range(ord(mn), ord(mx) + 1)]
expr = expr.replace('!', '~')
expr = expr.replace('-', '<=')
expr = expr.replace('+', '==')
n = len(chars)
ans = [[], []]
for i in range(1 << n):
    tmp_expr = expr
    for j in range(n):
        if i & (1 << (n - j - 1)):
            tmp_expr = tmp_expr.replace(chars[j], '1')
        else:
            tmp_expr = tmp_expr.replace(chars[j], '0')
    ans[eval(tmp_expr)] += [i]
if not ans[1]:
    print('0', end = "")
else:
    print(' ∨ '.join('m%s' % val for val in ans[1]), end="")
print(' ; ', end = "")
if not ans[0]:
    print('1', end = "")
else:
    print(' ∧ '.join('M%s' % val for val in ans[0]))
