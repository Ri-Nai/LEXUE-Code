# coding: utf-8
expr = raw_input()
chars = []
mn = 'z'
mx = 'a'
for i in expr:
    if i.isalpha():
        mx = max(mx, i)
        mn = min(mn, i)
    if i.isdigit():
        while True:
            pass
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
if len(ans[1]) == 0:
    print '0',
else:
    print ' ∨ '.join('m%s' % val for val in ans[1]),
print ';',
if len(ans[0]) == 0:
    print '1',
else:
    print ' ∧ '.join('M%s' % val for val in ans[0]),
print
