#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926;
int main()
{
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; ++i)
        cin >> X[i] >> Y[i];
    double ans = 0;
    vector<int> mark(n), P(n);
    auto check_ans = [&]() -> void
    {
        vector<double> R(n);
        double res = 0;
        for (int i = 0; i < n; ++i)
        {
            R[i] = min(min(abs(X[i] - x1), abs(x2 - X[i])),
                       min(abs(Y[i] - y1), abs(y2 - Y[i])));
            for (int j = 0; j < i; ++j)
                R[i] = min(R[i], -R[j] + sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])));
            res += pi * R[i] * R[i];
        }
        ans = max(ans, res);
    };
    auto dfs = [&](auto self, int x) -> void
    {
        if (x == n)
            return check_ans();
        for (int i = 0; i < n; ++i)
            if (!mark[i])
            {
                mark[i] = 1;
                P[x] = i;
                self(self, x + 1);
                mark[i] = 0;
            }
    };
    dfs(dfs, 0);
    ans = 1. * (y2 - y1) * (x2 - x1) - ans;
    cout << round(ans) << '\n';
}
