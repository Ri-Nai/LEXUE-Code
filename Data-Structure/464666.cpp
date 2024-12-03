#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    a.insert(a.end(), a.begin(), a.end());
    using VecIt = std::vector<int>::iterator;
    auto solve_dp = [&](VecIt (*func)(VecIt, VecIt))
    {
        std::vector<std::vector<int>> dp(n + n, std::vector<int>(n + n + 1));

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i + len <= n + n; ++i)
            {
                int l = i, r = i + len;
                std::vector<int> results;
                int sum = a[l];
                for (int k = l + 1; k < r; ++k)
                {
                    sum += a[k];
                    results.push_back(dp[l][k] + dp[k][r]);
                }
                dp[l][r] = *func(results.begin(), results.end()) + sum;
            }
        }
        std::vector<int> results;
        for (int i = 0; i < n; ++i)
            results.push_back(dp[i][i + n]);
        return *func(results.begin(), results.end());
    };

    std::cout << solve_dp(std::min_element) << std::endl;
    std::cout << solve_dp(std::max_element) << std::endl;
}
