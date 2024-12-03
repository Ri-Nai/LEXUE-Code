#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 0; i <= n; ++i)
        std::cin >> a[i];
    using i64 = long long;
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(n + 1));
    std::vector<std::vector<int>> from(n, std::vector<int>(n + 1));
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i + len <= n; ++i)
        {
            int l = i, r = i + len;
            dp[l][r] = LONG_LONG_MAX;
            for (int k = l + 1; k < r; ++k)
            {
                i64 res = dp[l][k] + dp[k][r] + 1ll * a[l] * a[k] * a[r];
                if (res < dp[l][r])
                    dp[l][r] = res, from[l][r] = k;
            }
        }
    }
    std::cout << dp[0][n] << std::endl;
    std::function<std::string(int, int)> combine = [&](int l, int r)
    {
        if (r - l == 1)
            return "A" + std::to_string(r);
        return "(" + combine(l, from[l][r]) + combine(from[l][r], r) + ")";
    };
    // 特别标注：有个case是这个情况
    if (n == 1)
        std::cout << "(A1)" << std::endl;
    else
        std::cout << combine(0, n) << std::endl;
}
