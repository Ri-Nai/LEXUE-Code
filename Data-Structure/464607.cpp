#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    auto solve = []()
    {
        int n, m;
        cin >> n >> m;
        if (m + 1 > n)
            return 0;
        auto Qpow = [](long long a, int b) -> long long
        {
            long long ans = 1;
            while (b)
            {
                if (b & 1)
                    ans = ans * a;
                if (ans > 1e9)
                    return 1e9;
                a = a * a;
                b >>= 1;
            }
            return ans;
        };
        if (Qpow(2, m + 1) - 1 >= n)
        {
            int l = 0, r = n, ans = 0;
            auto getCount = [&](int x) -> int
            {
                int dep = 0;
                long long total = 0;
                while (x > 1)
                {
                    ++dep;
                    total += x;
                    x = x + 1 >> 1;
                }
                total += m - dep + 1;
                return total <= n;
            };
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (getCount(mid))
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            return ans;
        }
        else
            return 1 << m;
    };
    while (T--)
        cout << solve() << endl;
}
