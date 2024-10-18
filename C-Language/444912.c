#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    if (!isalpha(c))
    {
        puts("Input error!");
        return 0;
    }
    c = toupper(c);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char now = 'A' + (c - 'A' + i + j) % 26;
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                putchar(now);
            else
                putchar(' ');
            if (j != n - 1)
                putchar(' ');
        }
        puts("");
    }
}
