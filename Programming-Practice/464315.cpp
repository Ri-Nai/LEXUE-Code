#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    n = n % 6 + (n / 6 > 0) * 6;
    int S = 1 << n;
    vector<int> dp(S);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        auto last = dp;
        auto convertStatus = [&](int status, int y)
        {
            auto isEven = [](int x) {return x % 2 == 0;};
            auto isOdd = [](int x) {return x % 2 == 1;};
            auto isMod3 = [](int x) {return x % 3 == 0;};
            vector<function<bool(int)>> f = {isEven, isOdd, isMod3};
            for (int i = 0; i < n; ++i)
                if (f[y](i))
                    status ^= 1 << i;
            return status;
        };
        for (int j = 0; j < S; ++j)
            for (int k = 0; k < 3; ++k)
                dp[convertStatus(j, k)] |= last[j];
    }
    cout << accumulate(dp.begin(), dp.end(), 0) << endl;
}
