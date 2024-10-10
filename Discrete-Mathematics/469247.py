expr = input()
chars = []
for i in expr:
    if i.isalpha():
        chars.append(i)
        expr = expr.replace(i, f'_{i}_')
chars = list(set(sorted(chars)))
expr.replace('-', '<=')
expr.replace('+', '==')

n = len(chars)
ans = [[], []]
for i in range(1 << n):
    tmp_expr = expr
    for j in range(n):
        if i & (1 << (n - j - 1)):
            tmp_expr = tmp_expr.replace(f'_{chars[j]}_', '1')
        else:
            tmp_expr = tmp_expr.replace(f'_{chars[j]}_', '0')
    ans[eval(tmp_expr)] += [i]
if len(ans[1]) == 0:
    # print('False')
    print('0', end='')
else:
    for i, val in enumerate(ans[1]):
        if i:
            print(' ∨ ', end='')
        print(f'm{val}', end='')
print(' ; ', end='')
if len(ans[0]) == 0:
    print('True')
else:
    for i, val in enumerate(ans[0]):
        if i:
            print(' ∧ ', end='')
        print(f'M{val}', end='')
"""
# coding: utf-8

expr = raw_input()
chars = []
for i in expr:
    if i.isalpha():
        chars.append(i)
        expr = expr.replace(i, '_%s_' % i)
chars = list(set(sorted(chars)))
expr = expr.replace('!', ' not ')
expr = expr.replace('&', ' and ')
expr = expr.replace('|', ' or ')
expr = expr.replace('-', ' <= ')
expr = expr.replace('+', ' == ')

n = len(chars)
ans = [[], []]
for i in range(1 << n):
    tmp_expr = expr
    for j in range(n):
        if i & (1 << (n - j - 1)):
            tmp_expr = tmp_expr.replace('_%s_' % chars[j], ' True ')
        else:
            tmp_expr = tmp_expr.replace('_%s_' % chars[j], ' False ')
    ans[eval(tmp_expr)] += [i]
if len(ans[1]) == 0:
    print '0',
else:
    print ' ∨ '.join('m%s' % val for val in ans[1])

print ' ; ',
if len(ans[0]) == 0:
    print '1'
else:
    print ' ∧ '.join('M%s' % val for val in ans[0])
print
"""
