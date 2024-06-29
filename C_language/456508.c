#include <stdio.h>
char s[223122];
int main()
{
    int n;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i)
        if (s[i] != s[i + 1])
            putchar(s[i]);
    puts("");
}
