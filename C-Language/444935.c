#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    long long ans = -1, now = 0, mn = 0;
    while (n--)
    {
        now -= 1;
        int x;
        scanf("%d", &x);
        if (x == 1) now += m;
        if (now - mn > ans) ans = now - mn;
        if (now < mn) mn = now;
    }
    printf("%lld\n", ans);
}
