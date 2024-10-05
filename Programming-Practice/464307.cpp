#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];
    double l = 0, r = 2e4, res = -1;
    while (r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        auto check = [&](double d)
        {
            double L = -1e9, R = 1e9;
            for (int i = 0; i < n; ++i)
            {
                double x = X[i], y = Y[i];
                if (d < fabs(Y[i]))
                    return false;
                double l = x - sqrt(d * d - y * y);
                double r = x + sqrt(d * d - y * y);
                L = max(l, L);
                R = min(r, R);
            }
            return L <= R;
        };
        if (check(mid))
            res = mid, r = mid;
        else
            l = mid;
    }
    printf("%.4lf\n", res);
}
