#include <stdio.h>
typedef long long ll;
ll base[80];
void Insert(ll x)
{
    for (int i = 63; i >= 0; --i)
        if (1ll << i & x)
        {
            if (!base[i]) base[i] = x;
            x ^= base[i];
        }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        scanf("%lld", &x);
        Insert(x);
    }
    ll ans = 0;
    for (int i = 63; i >= 0; --i)
    {
        if (1ll << i & ans)
            continue;
        ans ^= base[i];
    }
    printf("%lld\n", ans);
}
