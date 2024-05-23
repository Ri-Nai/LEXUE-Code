#include <stdio.h>
#include <stdlib.h>
#define N 202020
int *A[N], len[N], lim[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        A[i] = calloc(len[i] = lim[i] = 1, sizeof(int));
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (len[x] == lim[x])
        {
            A[x] = realloc(lim[x] <<= 1, sizeof(int));

        }
    }
}
