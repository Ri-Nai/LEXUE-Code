#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    using Pr = pair<int, int>;
    vector<vector<int>> A(n + 1, vector<int>(m + 1));
    vector<vector<Pr>> Pre(n + 1, vector<Pr>(m + 1, {0, 0}));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> A[i][j];

    auto get_pre = [&](Pr S)
    {
        return Pre[S.first][S.second];
    };
    auto print = [&](Pr S)
    {
        cout << "<" << S.first << "," << S.second << "> ";
    };
    function<void(Pr)> print_path = [&](Pr S)
    {
        if (S != make_pair(1, 1))
            print_path(get_pre(S));
        print(S);
    };
    auto check = [&](int x, int y)
    {
        return x >= 1 && y >= 1 && x <= n && y <= m;
    };
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    queue<Pr> Q;
    Pre[1][1] = {1, 1};
    Q.push({1, 1});
    while (!Q.empty())
    {
        auto P = Q.front();
        int x = P.first;
        int y = P.second;
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check(nx, ny) || A[nx][ny] || get_pre({nx, ny}).first)
                continue;
            Pre[nx][ny] = {x, y};
            Q.push({nx, ny});
        }
    }
    if (!get_pre({n, n}).first)
        cout << "There is no solution!";
    else
        print_path({n, n});
    cout << '\n';
}
