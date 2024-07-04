#include <stdio.h>
int main()
{
    int n, m, flag = 0;
    scanf("%d%d", &n, &m);
    for (int i = n; i >= 0; --i)
        for (int j = n - i; j >= 0; --j)
        {
            int k = n - i - j;
            int now = 120 * i + 34 * j + 23 * k;
            if (now == m * 10)
                (flag = 1) && printf("%d %d %d\n", i, j, k);
        }
    if (!flag)
        puts("Error!");
}
