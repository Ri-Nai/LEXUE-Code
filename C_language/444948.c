#include <stdio.h>
int has[2048];
int A[200];
int n;
int check(int x, int y, int p)
{
    if (x < 2048 && has[x])
        return 1;
    int res = x;
    if (p) res ^= y;
    else res |= y;
    return res < 2048 && has[res];
}
int main()
{
    int x;
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
            break;
        has[x] = 1;
        A[++n] = x;
    }
    getchar();
    char c = getchar();
    int first = 0;
    while (scanf("%d", &x) != EOF)
    {
        if (first)
            putchar(' ');
        int ans = 1;
        for (int i = 1; i <= n; ++i)
            ans &= check(x, A[i], c == '^');
        printf("%d", ans);
        first = 1;
    }
    puts("");
}
