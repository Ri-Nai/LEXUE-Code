#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    char slash, S;
    cin >> n >> slash >> m >> slash >> S;
    const long long INF = 1e18;
    vector<vector<long long>> dis(n, vector<long long>(n, INF));
    auto getId = [&](char c) { return c - 'a'; };
    for (int i = 0; i < n; ++i)
        dis[i][i] = 0;
    for (int i = 0; i < m; ++i)
    {
        char u, v;
        int w;
        cin >> slash >> u >> slash >> v >> slash >> w >> slash;
        // cout << u << " " << v << " " << w << endl;
        dis[getId(u)][getId(v)] = min(dis[getId(u)][getId(v)], w + 0ll);
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 0; i < n; ++i)
        cout << char(i + 'a') << ":" << dis[getId(S)][i] << endl;
}
