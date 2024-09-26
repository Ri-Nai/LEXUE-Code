#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; ++i)
        cin >> X[i] >> Y[i];
    auto xProduct = [&](int x1, int y1, int x2, int y2)
    {
        return 1ll * x1 * y2 - 1ll * y1 * x2;
    };
    auto getLengthPower = [&](int x1, int y1, int x2, int y2)
    {
        return 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
    };
    double ans = 0;
    auto check = [&](int u, int v)
    {
        bool flag = 0;
        long long last = 0;
        auto length = getLengthPower(X[u], Y[u], X[v], Y[v]);
        for (int i = 0; i < n; ++i)
        {
            if (i == u || i == v)
                continue;
            auto now = xProduct(X[u] - X[i], Y[u] - Y[i], X[u] - X[v], Y[u] - Y[v]);
            if (now == 0 &&
                (getLengthPower(X[u], Y[u], X[i], Y[i]) > length ||
                 getLengthPower(X[v], Y[v], X[i], Y[i]) > length))
            {
                return;
            }
            if (flag && last * now < 0)
                return;
            flag = 1;
            last = now;
        }
        ans += sqrt(length);
    };
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            check(i, j);
    cout << ans << '\n';
}
