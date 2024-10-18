#include <stdio.h>
#include <stdlib.h>
int A[201308];
int main()
{
    const int mod = 167772161;
    int ans = 1, n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++A[x];
    }
    for (int i = n; i >= 1; --i)
    {
        printf("%d\n", A[i]);
        ans = 1ll * ans * A[i] % mod;
        A[i-1] += A[i] - 1;
    }
    printf("%d\n", ans);
}
