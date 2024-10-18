#include <stdio.h>
#include <string.h>

void print_pattern(int n, int m, const char *s)
{
    int i, j;
    int len = strlen(s);
    int tot = (len * m - 1) / n + 1;
    for (i = 1; i <= tot; ++i)
    {
        int start_index = (i - 1) * n % len;
        printf("%*d:", 3, i);
        for (j = 0; j < n; ++j)
            if((i - 1) * n + j + 1 <= len * m)
                putchar(s[(start_index + j) % len]);
        putchar('\n');
    }
}

int main()
{
    int n = 9;
    int m = 5;
    char s[21323];
    scanf("%d%d%s", &n, &m, s);
    print_pattern(n, m, s);
    return 0;
}
