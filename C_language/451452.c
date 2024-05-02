#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int A[1000005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    qsort(A, n, sizeof(int), cmp);
    for (int i = 0; i < n; ++i)
        printf("%d%c", A[i], " \n"[i == n - 1]);
}
