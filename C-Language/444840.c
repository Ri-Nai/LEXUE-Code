#include <stdio.h>
#define N 100005
int A[N];
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
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
