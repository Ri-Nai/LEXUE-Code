#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);

    for (int i = 0; i < n; ++i)
        a[i].resize(i);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            std::cin >> a[j][i];
    std::vector<int> dp(n, 1145141919);
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] = std::min(dp[i], dp[j] + a[i][j]);
    std::cout << dp.back() << std::endl;
}
