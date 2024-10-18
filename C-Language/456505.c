#include <stdio.h>
void put(int x, char c, int is)
{
    for (int i = 0; i < x; ++i)
        putchar(c);
    if (is)
        puts("");
}
int main()
{
    int n;
    scanf("%d", &n);
    put(2 * n - 1, 'G', 1);
    for (int i = 2; i < 2 * n - 1; ++i)
    {
        putchar('G');
        if (i < n)
            put(2 * n - 2, '+', 1);
        else if (i == n)
            put(2 * n - 1 - n - 1, '+', 0), put(n, 'G', 1);
        else
            put(2 * n - 3, '+', 0), put(1, 'G', 1);
    }
    put(2 * n - 1, 'G', 1);
}
