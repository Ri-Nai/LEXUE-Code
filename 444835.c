#include <stdio.h>
char nxt(char now)
{
    if (now++ == 'Z')
        now = 'A';
    return now;
}
int main()
{
    int n;
    scanf("%d", &n);
    char now = 'A';
    for (int i = 1; i <= n; ++i)
        putchar(now), now = nxt(now);
    puts("");
    for (int i = 2; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
            putchar(' ');
        putchar(now);
        puts("");

        now = nxt(now);
    }
    if (n != 1)
        for (int i = 1; i <= n; ++i)
            putchar(now), now = nxt(now);
    puts("");
}
