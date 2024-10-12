#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m)), ans(n, vector<int>(m));
    // vector<vector<vector<vector<vector<int>>>>> dp(
    //     2, vector<vector<vector<vector<int>>>>(
    //            m, vector<vector<vector<int>>>(
    //               k + 1, vector<vector<int>>(
    //                      k + 1, vector<int>(k + 1, 0)))));
    vector dp(2, vector(m, vector(k + 1, vector(k + 1, vector<int>(k + 1)))));
    // vector<vector<vector<vector<vector<int>>>>> dp(2, vector<int>(k + 1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> b[i][j];
    auto Add = [&](int &a, int b)
    { a += b; if (a >= mod) a -= mod; };
    for (int i = 0; i < n; ++i)
    {
        int cur = i & 1;
        int pre = cur ^ 1;
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0)
                dp[cur][j][0][0][0] = 1;
            for (int c = 0; c <= k; ++c)
                for (int sa = 0; sa <= k - 1 && sa <= n - i - 1; ++sa)
                    for (int sb = 0; sb <= k - 1 && sb <= m - j - 1; ++sb)
                    {
                        if (i > 0)
                            dp[cur][j][c][sa][sb] = 0;
                        if (i > 0)
                            Add(dp[cur][j][c][sa][sb], dp[pre][j][c][sa + 1][sb]);
                        if (j > 0)
                            Add(dp[cur][j][c][sa][sb], dp[cur][j - 1][c][sa][sb + 1]);
                    }
            for (int c = 0; c <= k - a[i][j]; ++c)
                for (int sa = 0; sa <= k - 1 && sa <= n - i - 1; ++sa)
                    for (int sb = 0; sb <= k && sb <= m - j - 1; ++sb)
                        Add(dp[cur][j][c + a[i][j]][sa + 1][sb], dp[cur][j][c][sa][sb]);
            for (int c = 0; c <= k - b[i][j]; ++c)
                for (int sa = 0; sa <= k && sa <= n - i - 1; ++sa)
                    for (int sb = 0; sb <= k - 1 && sb <= m - j - 1; ++sb)
                        Add(dp[cur][j][c + b[i][j]][sa][sb + 1], dp[cur][j][c][sa][sb]);
            ans[i][j] = dp[cur][j][k][0][0];
        }
    }
    for (int i = 0; i < n; ++i, puts(""))
        for (int j = 0; j < m; ++j)
            cout << ans[i][j] << ' ';
}
