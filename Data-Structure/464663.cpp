#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
            std::cin >> a[i][j];
    }
    auto dp = a;
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] += dp[i - 1][j];
            else if (j == i)
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += std::max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    std::cout << *std::max_element(dp[n - 1].begin(), dp[n - 1].end()) << std::endl;

}
