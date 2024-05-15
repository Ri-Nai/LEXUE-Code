#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, x, y;
        scanf("%d%d%d%d", &n, &m, &x, &y);
        int ans = n - x ^ x - 1 ^ m - y ^ y - 1;
        if (ans != 0)
            puts("win");
        else puts("lose");
    }
}
