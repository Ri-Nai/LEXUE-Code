#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, num;
    cin >> m >> num;
    typedef long long ll;
    vector<ll> pw(1, 1);
    for (int i = 1; i <= 18; ++i)
        pw.push_back(pw.back() * 10);
    auto getArray = [&](ll x)
    {
        vector<int> number;
        while (x)
        {
            number.push_back(x % 10);
            x /= 10;
        }
        reverse(number.begin(), number.end());
        return number;
    };
    auto base = getArray(m);
    auto check = [&](ll limit)
    {
        ll sum = 0;
        auto now = getArray(limit);
        for (int length = 1; length < base.size(); ++length)
            sum += m / pw[base.size() - length] - pw[length - 1] + 1;
        for (int length = base.size(); length <= now.size(); ++length)
        {
            ll shift = m * pw[length - base.size()];
            sum += min(limit, shift - (length != base.size())) - pw[length - 1] + 1;
        }
        return sum;
    };
    if (check(m) > num)
    {
        cout << 0 << endl;
        return 0;
    }
    ll l = m, r = 4e18, ans = 0;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (check(mid) >= num)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;

}
/*
100000001
1000000000
*/
