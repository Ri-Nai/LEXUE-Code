#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e6 + 5;
int num[N], cost[N], counts[N], tot;
signed main()
{
    int n;
    cin >> n;
    // vector<int> num(n), cost(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &cost[i]);
    ull ans = 0;
    sort(num, num + n);
    sort(cost, cost + n);
    if (num[0] == num[n - 1])
    {
        for (int i = 0; i < n - 1; ++i)
            ans += 1ll * cost[i] * (n - i - 1);
        cout << ans << endl;
        return 0;
    }
    set<int> S;
    for (int i = 0; i < n; ++i)
    {
        int j = i;
        while ((j + 1) < n && num[j + 1] - num[i] < (j + 1) - i)
            ++j;
        for (int k = i + 1; k <= j; ++k)
            S.insert(num[i] + k - i);
        for (int k = j; k >= i + 1; --k)
        {
            auto it = S.lower_bound(num[k]);
            int now = *it - num[k];
            counts[tot++] = now;
            S.erase(it);
        }
        i = j;
    }
    sort(counts, counts + tot, greater<int>());
    for (int i = 0; i < tot; ++i)
        ans += 1ll * counts[i] * cost[i];
    cout << ans << endl;
}
/*
你有 n 个物品，每个物有一个权值a_i和费用cost_i
你可以进行以下操作：
选择一个 i，a_i += 1并花费cost_i
你一开始可以将cost_i重排
求问将物品权值变得互不相同最小花费
*/
