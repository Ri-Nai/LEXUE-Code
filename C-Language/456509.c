#include <stdio.h>
const char ch[] = " *";
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
    for (int i = 1; i <= n; ++i)
    {
        putchar('*');
        put(n - 1, ch[i == n], 0);
        putchar(' ');
        putchar('*');
        put(n - 2, ch[i == n || i == 1], 0);
        putchar('*');
        putchar(' ');
        putchar('*');
        put(i == n ? n - 1 : 0, '*', 1);
    }
}
