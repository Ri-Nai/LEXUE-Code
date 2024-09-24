#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];
    vector<int> valid;
    int S = 1 << m;
    for (int i = 0; i < S; ++i)
        if (!((i >> 1 | i << 1) & i))
            valid.push_back(i);
    vector<vector<int>> dp(n, vector<int>(S));
    vector<vector<int>> sum(n, vector<int>(S));
    for (int i = 0; i < n; ++i)
        for (int now : valid)
            for (int j = 0; j < m; ++j)
                if (now >> j & 1)
                    sum[i][now] += A[i][j];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int now : valid)
        {
            if (i == 0)
                dp[i][now] = sum[i][now];
            else
                for (int last : valid)
                {
                    if ((last >> 1 | last | last << 1 ) & now)
                        continue;
                    dp[i][now] = max(dp[i][now], dp[i - 1][last] + sum[i][now]);
                    ans = max(ans, dp[i][now]);
                }
        }
    }
    cout << ans << '\n';
}
