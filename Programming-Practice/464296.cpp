#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i)
        cin >> B[i];
    vector<int> dp(m + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= 0; --j)
        {
            int val = abs(A[i] - B[i]);
            int res = 1e9;
            for (int k = 0; k <= j; ++k)
                res = min(res, dp[j - k] + (val - k) * (val - k));
            dp[j] = res;
        }
    cout << dp[m] << '\n';
}
