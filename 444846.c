#include <stdio.h>
#include <string.h>
int beg[105];
char s[2][105];
int main()
{
    scanf("%s%s", s[0], s[1]);
    int n = strlen(s[0]);
    int tot = 0;
    for (int i = 0; i <= n - 6; ++i)
    {
        if (s[0][i] == s[0][i + 1] && s[0][i] == s[0][i + 2] && (s[0][i] | s[0][i + 3]) == ('C' | 'G') && s[0][i + 3] == s[0][i + 4] && s[0][i + 3] == s[0][i + 5])
        {
            beg[++tot] = i + 3;
            i += 2;
        }
    }
    beg[++tot] = n;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = tot; j > 0; --j)
        {
            for (int k = beg[j - 1]; k < beg[j]; ++k)
                putchar(s[i][k]);
        }
        puts("");
    }
}
