#include <stdio.h>
int A[202020];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    int now = 0;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0)
            now += y;
        else
            A[y] = -A[y] - 2 * now;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", A[i] + now);
}
