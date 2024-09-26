#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long m;
    cin >> n >> m;
    vector<int> A(n);
    vector<long long> fac(n);
    fac[0] = 1;
    for (int i = 1; i < n; ++i)
        fac[i] = fac[i - 1] * i;
    auto C = [&](int n, int m)
    {
        return fac[n] / fac[m] / fac[n - m]; 
    };
    vector<int> mark(n);
    function<void(int, int)> dfs = [&](int u, long long now)
    {
        if (now < 0)
            return;
        if (u == n)
        {
            if (now == 0)
            {
                for (int i = 0; i < n; ++i)
                    cout << A[i] << " \n"[i == n - 1];
                exit(0);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (mark[i])
                continue;
            mark[i] = 1;
            A[u] = i + 1;
            dfs(u + 1, now - C(n - 1, u) * A[u]);
            mark[i] = 0;
        }
    };
    dfs(0, m);
    
}
