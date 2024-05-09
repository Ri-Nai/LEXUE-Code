#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[2005][15];
int id[2005];
int pos[2005];
int cmp(const void *a, const void *b)
{
    return strcmp(s[*(int *)a], s[*(int *)b]);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[id[i] = i]);
    qsort(id + 1, n, sizeof(int), cmp);
    for (int i = 1; i <= n; ++i)
        pos[id[i]] = i;
    for (int i = 1; i <= n; ++i)
        printf("%d\n", pos[i]);

}
