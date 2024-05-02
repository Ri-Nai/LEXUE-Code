#include <stdio.h>
#include <stdlib.h>
int n, m;
int main()
{
    scanf("%d", &n);
    int *A = (int *)(calloc(n + 1, sizeof(int)));
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        printf("%d%c", A[i] + x, " \n"[i == n]);
    }
}
