#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> name;
    string s;
    while (cin >> s, s != "*")
        name.push_back(s);
    int n = name.size();
    int u, v;
    char c;
    vector<vector<int>> edge(n);
    while (cin >> u >> c >> v, u != -1)
        edge[u].push_back(v), edge[v].push_back(u);
    for (int i = 0; i < n; ++i)
        reverse(edge[i].begin(), edge[i].end());
    cout << "the ALGraph is" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << name[i];
        for (int j = 0; j < edge[i].size(); ++j)
            cout << " " << edge[i][j];
        cout << endl;
    }
    cout << "the Breadth-First-Seacrh list:";
    queue<int> Q;
    vector<int> mark(n);
    for (int i = 0; i < n; ++i)
    {
        if (!mark[i])
            Q.push(i), mark[i] = 1;
        while (!Q.empty())
        {
            int u = Q.front();
            cout << name[u];
            Q.pop();
            for (int v : edge[u])
                if (!mark[v])
                    Q.push(v), mark[v] = 1;
        }
    }
    cout << endl;
}
