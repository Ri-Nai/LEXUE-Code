#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pos;
    vector<int> markRows(n), markCols(n), markDiag1(n + n), markDiag2(n + n);

    auto check = [&](int x, int y)
    {
        return !markRows[x] && !markCols[y] && !markDiag1[x + y] && !markDiag2[x - y + n];
    };
    int ans = 0;
    function<void(int, int)> dfs = [&](int i, int now)
    {
        if (now == m)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (check(i, j))
                        return;
            ++ans;
            return;
        }
        if (i >= n)
            return;
        dfs(i + 1, now);
        for (int j = 0; j < n; ++j)
        {
            if (!check(i, j))
                continue;
            ++markRows[i];
            ++markCols[j];
            ++markDiag1[i + j];
            ++markDiag2[i - j + n];
            dfs(i + 1, now + 1);
            --markRows[i];
            --markCols[j];
            --markDiag1[i + j];
            --markDiag2[i - j + n];
        }
    };
    dfs(0, 0);
    cout << ans << endl;
}

