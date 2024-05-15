#include <stdio.h>
#define N 5005
int A[N];
long long check(int *A, int n, int k, int p)
{
    long long tot = 0;
    for (int i = 0; i < n; ++i)
        if (A[i] < p)
            tot += p - A[i];
    return tot;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    int l = 0, r = 2000000000, ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(A, n, k, mid) <= k)
            l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    int res = k - check(A, n, k, ans);
    for (int i = 0; i < n; ++i)
        if (A[i] > ans) ++res;
    printf("%d %d\n", ans, res);
}
