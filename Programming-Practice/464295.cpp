#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> cnt(2);
    vector<ll> sum(2);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        ++cnt[x & 1];
        sum[x & 1] += x;
    }
    for (int i = 1; i <= q; ++i)
    {
        int op, x;
        cin >> op >> x;
        op &= 1;
        if (x & 1)
        {
            sum[op ^ 1] += sum[op] + 1ll * x * cnt[op];
            cnt[op ^ 1] += cnt[op];
            sum[op] = cnt[op] = 0;
        }
        else
            sum[op] = sum[op] + 1ll * x * cnt[op];
    }
    cout << sum[0] + sum[1] << '\n';
}
