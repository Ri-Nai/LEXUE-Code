#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d,%d", &n, &m);
    getchar();
    struct Node
    {
        int idx;
        string name;
        Node() {}
        Node(int _idx, string _name) : idx(_idx), name(_name) {}
        bool operator<(const Node &a) const
        {
            return name > a.name;
        }
    };
    vector<Node> v;
    string data;
    getline(cin, data);
    stringstream ss(data);

    for (int i = 0; i < n; ++i)
    {
        getline(ss, data, ',');
        v.push_back(Node(i, data));
    }

    vector<vector<array<int, 2>>> edge(n);
    vector<int> ind(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("<%d,%d,%d>", &u, &v, &w);
        edge[u].push_back({v, w});
        ++ind[v];
        getchar();
    }
    priority_queue<Node> q;
    int start = -1;
    for (int i = 0; i < n; ++i)
    {
        if (ind[i] == 0)
        {
            start = i;
            q.push(v[i]);
        }
    }
    int cnt = 0;
    vector<string> ans;
    while (!q.empty())
    {
        int u = q.top().idx;
        q.pop();
        ++cnt;
        ans.push_back(v[u].name);
        for (auto e : edge[u])
        {
            --ind[e[0]];
            if (ind[e[0]] == 0)
                q.push(v[e[0]]);
        }
    }
    if (cnt < n)
    {
        puts("NO TOPOLOGICAL PATH");
        return 0;
    }
    auto print = [](vector<string> ans)
    {
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << "-\n"[i == ans.size() - 1];
    };
    print(ans);
    vector<vector<string>> path;
    int mxlength = 0;
    function<void(int, int, vector<string>)> dfs = [&](int u, int p, vector<string> res)
    {
        res.push_back(v[u].name);
        if (p > mxlength)
        {
            mxlength = p;
            path.clear();
            path.push_back(res);
        }
        else if (p == mxlength)
            path.push_back(res);
        for (auto e : edge[u])
        {
            int v = e[0];
            int w = e[1];
            dfs(v, p + w, res);
        }
    };
    dfs(start, 0, {});
    sort(path.begin(), path.end());
    for (auto p : path)
        print(p);
}
