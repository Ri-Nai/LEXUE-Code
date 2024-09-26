#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
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
    vector<int> P(n);
    auto check_ans = [&]() -> void
    {
        vector<double> R(n);
        double res = 0;
        for (int i = 0; i < n; ++i)
        {
            int u = P[i];
            R[i] = min(min(abs(X[u] - x1), abs(x2 - X[u])),
                       min(abs(Y[u] - y1), abs(y2 - Y[u])));
            for (int j = 0, v; j < i && 1 + (v = P[j]); ++j)
                R[i] = min(R[i], -R[j] + sqrt((X[u] - X[v]) * (X[u] - X[v]) + (Y[u] - Y[v]) * (Y[u] - Y[v])));
            R[i] = max(R[i], 0.);
            res += pi * R[i] * R[i];
        }
        ans = max(ans, res);
    };
    iota(P.begin(), P.end(), 0);
    do
        check_ans();
    while (next_permutation(P.begin(), P.end()));
    ans = 1. * (y2 - y1) * (x2 - x1) - ans;
    printf("%.0lf\n", ans);
}
