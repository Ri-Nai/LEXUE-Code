#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<tuple<int, int, int>> edge;
    int n, m;
    cin >> n >> m;
    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](int x)
    {
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    };
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }
    sort(edge.begin(), edge.end());
    int tot = 0;
    long long ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        u = find(get<1>(edge[i]));
        v = find(get<2>(edge[i]));
        w = get<0>(edge[i]);
        if (u == v)
            continue;
        fa[v] = u;
        ++tot;
        ans += w;
    }
    if (tot != n - 1)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}
