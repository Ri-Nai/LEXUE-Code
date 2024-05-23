#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int id[15];
char s[15][55];
int cmp1(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
int cmp2(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (*s[x] != *s[y])
        return -strcmp(s[x], s[y]);
    return (x - y > 0) ? 1 : -1;
}
int main()
{

    int t = 0;
    while (~scanf("%s", s[t]))
        qsort(s[id[t] = t], strlen(s[t]), sizeof(char), cmp1), ++t;
    qsort(id, t, sizeof(int), cmp2);
    for (int i = 0; i < t; ++i)
        puts(s[id[i]]);
}
