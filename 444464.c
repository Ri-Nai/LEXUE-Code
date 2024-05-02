#include <stdio.h>
#include <stdlib.h>
int cmp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}
int n, m;
int Dragon[105], Warrior[105];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &Dragon[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &Warrior[i]);
    qsort(Dragon, n, sizeof(int), cmp);
    qsort(Warrior, m, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j < m && Warrior[j] < Dragon[i])
            ++j;
        if (j == m)
        {
            puts("bit is doomed!");
            return 0;
        }
        ans += Warrior[j++];
    }
    printf("%d\n", ans);
}
