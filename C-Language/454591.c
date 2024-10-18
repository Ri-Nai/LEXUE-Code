#include <stdio.h>
int main()
{
    int n;
    long long A[24];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &A[i]);
    long long ans = 0;
    for (int i = 1; i < (1 << n); ++i)
    {
        long long now = 0;
        for (int j = 0; j < n; ++j)
            if (1 << j & i)
                now ^= A[j];
        if (now > ans)
            ans = now;
    }
    printf("%lld\n", ans);
}
