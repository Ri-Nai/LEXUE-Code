#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char s[1005];
char ns[1005][1005];
int id[1005];
int cmp(const void *a, const void *b)
{
    return strcmp(ns[*(int *)a], ns[*(int *) b]);
}
int main()
{
    int len = 0;
    int now = 0;
    while (1)
    {
        char c = getchar();
        if (isalnum(c) || c == '_')
            s[len++] = c;
        else
        {
            s[len] = 0;
            if (len != 0)
                strcpy(ns[now++], s);
            len = 0;
            if (c == '\n')
                break;
        }
    }
    ns[now++][0] = '0';
    for (int i = 0; i < now; ++i)
        id[i] = i;
    qsort(id, now - 1, sizeof(int), cmp);
    int cnt = 0, mx = 0;
    for (int i = 0; i < now; ++i)
    {
        int p = id[i], q = id[i - 1];
        if (i && strcmp(ns[p], ns[q]))
        {
            if (cnt > mx)
                strcpy(s, ns[q]), mx = cnt;
            cnt = 0;
        }
        if (isdigit(ns[p][0]))
            continue;
        ++cnt;
    }
    if (mx == 0)
        puts("No identifier!");
    else printf("%s\n", s);
}
