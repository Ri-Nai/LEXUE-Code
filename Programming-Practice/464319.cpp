#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    long long W;
    cin >> W >> m >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i)
    {
        int v, w;
        cin >> v >> w;
        v /= 1000;
        arr.emplace_back(v, w);
    }
    auto run = [&](int W)
    {
        int total = W / 1000;
        vector<int> dp(total + 1);
        for (int i = 0; i < n; ++i)
        {
            int v = arr[i].first, w = arr[i].second;
            for (int j = v; j <= total; ++j)
                dp[j] = max(dp[j], dp[j - v] + w);
        }
        return W + dp[total];
    };
    for (int i = 1; i <= m; ++i)
        W = run(W);
    cout << W << endl;
}
