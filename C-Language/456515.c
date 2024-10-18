#include <stdio.h>
#define N 500005
int A[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int len = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x != 0)
            A[len++] = x;
        else --m;
    }
    long long ans = 0;
    if (m < 0)
        puts("impossible");
    else if (m == len)
        puts("fuge vivo 50");
    else
    {
        for (int i = 0; i < m; ++i)
            ans += A[i];
        int mn = 2e9;
        for (int i = m; i < len; ++i)
            if (A[i] < mn) mn = A[i];
        printf("%lld\n", ans + mn - 1);
    }
}
