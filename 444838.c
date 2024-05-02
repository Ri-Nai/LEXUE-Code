#include <stdio.h>
#define N (int)(6e5 + 5)
int Pr[N], P[N], tot;
long long Sum[N];
void Pre()
{
    P[1] = 1;
    Sum[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (!P[i])
            P[i] = i - 1, Pr[++tot] = i;
        for (int j = 1; j <= tot; ++j)
        {
            int p = Pr[j];
            long long q = 1ll * p * i;
            if (q >= N)
                break;
            if (i % p == 0)
            {
                P[q] = P[i] * p;
                break;
            }
            P[q] = P[i] * P[p];
        }
        Sum[i] = Sum[i - 1] + P[i];
    }
}
void Solve()
{
    int n;
    long long D;
    scanf("%d%lld", &n, &D);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (D % i)
            continue;
        int m = n / i;
        ans += Sum[m];
    }
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    Pre();
    while (T--)
        Solve();
}
