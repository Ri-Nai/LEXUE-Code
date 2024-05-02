#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if (b > a)
        return b;
    return a;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int abs(int x)
{
    return x > 0 ? x : -x;
}
int main()
{
    int n, m, p, q;
    scanf("%d%d%d%d", &n, &m, &p, &q);
    int x = max(n, p), y = max(m, q);
    long long **ans = (long long **)calloc((x + 1), sizeof(long long *));
    for (int i = 0; i <= x; ++i)
        ans[i] = (long long *)calloc((y + 1), sizeof(long long));
    ans[0][0] = 1;
    for (int i = 0; i <= x; ++i)
        for (int j = 0; j <= y; ++j)
        {
            if (!i && !j)
                continue;
            if (i)
                ans[i][j] += ans[i - 1][j];
            if (j)
                ans[i][j] += ans[i][j - 1];
        }
    // puts("AAAA");
    printf("%lld\n", ans[p][q] * ans[abs(p - n)][abs(q - m)]);
    for (int i = 0; i <= p; ++i)
        printf("(%d,0)", i);
    for (int i = 1; i <= q; ++i)
        printf("(%d,%d)", p, i);
    for (int i = q - 1; i >= m; --i)
        printf("(%d,%d)", p, i);
    for (int i = p - 1; i >= n; --i)
        printf("(%d,%d)", i, min(m, q));
    for (int i = p + 1; i <= n; ++i)
        printf("(%d,%d)", i, min(m, q));
    for (int i = q + 1; i <= m; ++i)
        printf("(%d,%d)", n, i);
    puts("");
    for (int i = 0; i <= n; ++i)
        free(ans[i]);
    free(ans);
}
