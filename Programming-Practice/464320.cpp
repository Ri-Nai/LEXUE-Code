#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L, S, T, m;
    cin >> L >> S >> T >> m;
    vector<int> stone;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        stone.push_back(x);
    }
    if (S == T)
    {
        int ans = 0;
        for (int x : stone)
            ans += x % S == 0;
        cout << ans << endl;
        return 0;
    }
    stone.push_back(0);
    stone.push_back(L);
    sort(stone.begin(), stone.end());
    for (int i = stone.size() - 1; i >= 1; --i)
    {
        stone[i] -= stone[i - 1];
        stone[i] = min(stone[i], S * T + 114);
    }
    // cout << L << endl;
    for (int i = 1; i < stone.size(); ++i)
        stone[i] += stone[i - 1];
    L = stone.back();
    vector<int> dp(L + 1, 1114514), has(L + 1);
    for (int i = 1; i < stone.size() - 1; ++i)
        has[stone[i]] = 1;
    dp[0] = 0;
    for (int i = 1; i <= L; ++i)
        for (int j = S; j <= T; ++j)
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + has[i]);
    cout << dp[L] << endl;
}
