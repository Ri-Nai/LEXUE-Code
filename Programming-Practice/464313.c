#include <stdio.h>
#include <stdlib.h>
#define N 2000005
int *A, *B, n;
long long ans;
void MergeSort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
        {
            B[k++] = A[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= r)
        B[k++] = A[j++];
    for (int i = l; i <= r; i++)
        A[i] = B[i];
}
int main()
{
    while (~scanf("%d", &n))
    {
        ans = 0;
        A = (int *)malloc((n + 1) * sizeof(int));
        B = (int *)malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        MergeSort(1, n);
        printf("%lld\n", ans);
        free(A);
        free(B);
    }
    return 0;
}
