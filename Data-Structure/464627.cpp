#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    auto solve = [&]()
    {
        vector<vector<int>> edge(n);
        for (int i = 0; i < n; ++i)
        {
            int x, t;
            scanf("%d:(%d)", &x, &t);
            while (t--)
            {
                int y;
                scanf("%d", &y);
                edge[x].push_back(y);
                edge[y].push_back(x);
            }
        }
        vector<vector<int>> dp(n, vector<int>(2, 114514));
        function<void(int, int)> dfs = [&](int u, int f)
        {
            dp[u][0] = 0;
            dp[u][1] = 1;
            for (int v : edge[u])
            {
                if (v == f)
                    continue;
                dfs(v, u);
                dp[u][0] += dp[v][1];
                dp[u][1] += min(dp[v][0], dp[v][1]);
            }
        };
        dfs(0, -1);
        cout << min(dp[0][0], dp[0][1]) << endl;
    };
    while (cin >> n)
        solve();
}
