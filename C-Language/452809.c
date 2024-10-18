#include <stdio.h>
int n, m;
int A[100005];
int C[100005];
void Add(int x, int y)
{
    while (x <= n)
        C[x] += y, x += x & -x;
}
int Sum(int x)
{
    int res = 0;
    while (x)
        res += C[x], x -= x & -x;
    return res;
}
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        A[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        swap(&A[l], &A[r]);
    }
    long long res = 1ll * n * (n - 1) / 2;
    for (int i = 1; i <= n; ++i)
        res -= Sum(A[i]), Add(A[i], 1);
    printf("%lld\n", res);
}
