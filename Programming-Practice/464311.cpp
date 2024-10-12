#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    --x, --y;
    int m = 1 << n;
    vector<vector<int>> color(m, vector<int>(m));
    int tot = 0;
    function<void(int, int, int, int, int)> dfs = [&](int n, int x, int y, int x0, int y0)
    {
        if (n == 0)
            return;
        if (n == 1)
        {
            ++tot;
            // cout << n << ' ' << x << ' ' << y << ' ' << x0 << ' ' << y0 << ' ' << tot << '\n';
            for (int i : {0, 1})
                for (int j : {0, 1})
                    if (i != x || j != y)
                        color[x0 + i][y0 + j] = tot;
            return;
        }
        int len = 1 << n - 1;
        int status = (x >= len) << 1 | (y >= len);
        int now = ++tot;
        for (int i = 0; i < 4; ++i)
        {
            // int xt = x0 - , yt = y0;
            int xt = (i >> 1 ^ 1) * (len - 1), yt = (i & 1 ^ 1) * (len - 1);
            int nx = x0 + (i >> 1) * len, ny = y0 + (i & 1) * len;
            if (i == status)
                xt = x - (i >> 1) * len, yt = y - (i & 1) * len;
            else
                color[nx + xt][ny + yt] = now;
            dfs(n - 1, xt, yt, nx, ny);
        }
    };
    dfs(n, x, y, 0, 0);
    vector<int> mark(tot + 1);
    int ans = 0;
    for (auto v : color)
        for (auto u : v)
            if (u && !mark[u])
                mark[u] = ++ans;
    for (auto &v : color)
        for (auto &u : v)
            u = mark[u];
    for (auto v : color)
    {
        for (auto u : v)
            printf("%d ", u);
        puts("");
    }
}
