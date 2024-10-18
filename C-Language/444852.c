#include <stdio.h>
void Print(int n, char c)
{
    for (int i = 0; i < n; ++i)
        putchar(c);
}
void Print_mid(int max, int n)
{
    Print((max - n) / 2, ' ');
    Print(n, '*');
    puts("");
}
int main()
{
    int n;
    scanf("%d", &n);
    int m = (n - 1) % 3 + 1;
    n = (n - m) / 3;
    int max = 3 + 8 * n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 3; ++j)
            Print_mid(max, 3 + j * 4 * i);
    for (int i = 1; i <= m; ++i)
        Print_mid(max, 3);
}
