#include <stdio.h>

int isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
char nxt(char c, int t)
{
    if (isVowel(c))
        ++c;
    while (t--)
    {
        if (isVowel(c))
            ++c;
        ++c;
        if (isVowel(c))
            ++c;
        if (c == 'z' + 1)
            c = 'b';
    }
    return c;
}
int main()
{
    int n;
    char startChar;
    scanf("%d %c", &n, &startChar);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
            putchar(' ');
        putchar(nxt(startChar, i - 1));
        for (int j = 1; j < 2 * n - 2 * i; ++j)
            putchar(' ');
        if (i != n)
            putchar(nxt(startChar, n + n - i - 1));
        putchar('\n');
    }
    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 1; j < i; ++j)
            putchar(' ');
        putchar(nxt(startChar, i - 1));
        for (int j = 1; j < 2 * n - 2 * i; ++j)
            putchar(' ');
        putchar(nxt(startChar, n + n - i - 1));
        putchar('\n');
    }
}
