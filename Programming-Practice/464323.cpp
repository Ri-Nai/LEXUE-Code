#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> num(n), cost(n);
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    sort(num.begin(), num.end());
    ull ans = 0;
    vector<int> counts;
    vector<int> S;
    for (int i = 0; i < n; ++i)
    {
        int j = i;
        while ((j + 1) < n && num[j + 1] - num[i] < (j + 1) - i)
            ++j;
        int top = num[i] + j - i;
        for (int k = j; k >= i; --k)
        {
            while (top >= num[k])
                S.push_back(top--);
            int now = S.back() - num[k];
            S.pop_back();
            counts.push_back(now);
        }
        i = j;
    }
    sort(counts.begin(), counts.end(), greater<int>());
    sort(cost.begin(), cost.end());
    for (int i = 0; i < counts.size(); ++i)
        ans += 1ll * counts[i] * cost[i];
    cout << ans << endl;
}
