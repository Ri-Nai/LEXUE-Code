#include <stdio.h>
int A[1005], B[1005], n;
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]), B[A[i]] = i;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (A[i] == i)
            continue;
        swap(&A[B[i]], &A[i]);
        swap(&B[A[i]], &B[A[B[A[i]]]]);
        ++ans;
    }
    // for (int i = 1; i <= n; ++i)
    //     printf("%d ",A[i]);
    printf("%d\n", ans);
}
