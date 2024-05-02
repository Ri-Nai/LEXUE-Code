#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 2; i <= n; ++i)
        ans = (ans + m) % i;
    printf("%d\n", ans + 1);
}
