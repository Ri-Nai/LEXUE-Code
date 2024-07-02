#include <stdio.h>
void put(int m, char c)
{
    for (size_t i = 0; i < m; i++)
        putchar(c);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        put(i, ' ');
        int total = 2 * n - 2 * i - 1;
        int dep = 2 * m;
        int blank = total - dep;
        if (blank < 0)
        {
            put(total, '*');
            puts("");
        }
        else
        {
            put(m, '*');
            put(blank, ' ');
            put(m, '*');
            puts("");
        }
    }
}
