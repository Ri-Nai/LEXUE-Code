#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    typedef long long ll;
    auto Qpow = [](ll a, int b)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    };
    auto Qsqrt = [&](ll a, int b)
    {
        int l = 1, r = n, res = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (Qpow(mid, b) >= a)
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    };
    auto check = [&](ll x, int p)
    {
        return Qpow(Qsqrt(x, p), p) == x;
    };

    vector<ll> hash(3);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 3; ++j)
            hash[j] ^= Qpow(i, j + 1);
    for (int i = 1; i <= n - 2; ++i)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 3; ++j)
            hash[j] ^= Qpow(x, j + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        bool flag = 1;
        for (int j = 0; flag && j < 3; ++j)
        {
            ll x = hash[j] ^ Qpow(i, j + 1);
            if (!check(x, j + 1))
                flag = 0;
        }
        if (flag)
        {
            cout << i << ' ' << (hash[0] ^ i) << endl;
            return 0;
        }
    }
}
