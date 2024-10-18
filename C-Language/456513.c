#include <stdio.h>
#define int long long
int dis(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
main()
{
    int n, x1, x2, r1, r2;
    scanf("%lld%lld%lld%lld%lld", &n, &x1, &r1, &x2, &r2);
    for (int y = n; y >= -n; --y, putchar('\n'))
        for (int x = -n; x <= n; ++x)
        {
            if (dis(x, y, x1, 0) <= r1 * r1 && dis(x, y, x2, 0) >= r2 * r2)
                putchar('*');
            else putchar('.');
        }
}
