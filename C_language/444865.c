#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int cnt[26], id[26];
int cmp(const void *a, const void *b)
{
    return cnt[*(int *)b] - cnt[*(int *)a];
}
int main()
{
    char c;
    while((c = getchar()) != '\n')
        ++cnt[toupper(c) - 'A'];
    for (int i = 0; i < 26; ++i)
        id[i] = i;
    qsort(id, 26, sizeof(int), cmp);
    int mx = cnt[id[0]];
    for (int i = mx; i >= 1; --i)
    {
        for (int j = 0; j < 26; ++j)
        {
            putchar(" #"[cnt[id[j]] >= i]);
            putchar(" \n"[j == 25]);
        }
    }
    for (int i = 0; i < 26; ++i)
        printf("%c%c", 'A' + id[i], " \n"[i == 25]);
}
