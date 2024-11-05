#include <bits/stdc++.h>
using namespace std;
int main()
{
    struct BIT
    {
        int n, initial;
        vector<int> C;
        function<int(int, int)> work;
        BIT() {};
        BIT(int n, int initial, function<int(int, int)> work)
        {
            this->n = n;
            this->work = work;
            this->initial = initial;
            C.resize(n + 1, initial);
        }
        void modify(int x, int y)
        {
            while (x <= n)
                C[x] = work(C[x], y), x += x & -x;
        }
        int query(int x)
        {
            int ans = initial;
            while (x)
                ans = work(ans, C[x]), x -= x & -x;
            return ans;
        }
    };
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    BIT leftMin(n, -1e9, [](int a, int b)
                { return max(a, b); });
    BIT leftMax(n, -1e9, [](int a, int b)
                { return max(a, b); });
    for (int i = 1; i <= n; ++i)
    {
        l[i] = min(leftMax.query(n - p[i] + 1), leftMin.query(p[i])) - 1;
        leftMax.modify(n - p[i] + 1, i);
        leftMin.modify(p[i], i);
    }
    BIT rightMin(n, 1e9, [](int a, int b)
                 { return min(a, b); });
    BIT rightMax(n, 1e9, [](int a, int b)
                 { return min(a, b); });
    for (int i = n; i >= 1; --i)
    {
        r[i] = max(rightMax.query(n - p[i] + 1), rightMin.query(p[i])) + 1;
        rightMax.modify(n - p[i] + 1, i);
        rightMin.modify(p[i], i);
    }
    long long ans = 0;
    BIT sum(n, 0, [](int a, int b)
            { return a + b; });
    vector<vector<int>> has(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (l[i] > 0)
            has[l[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (r[i] <= n)
            sum.modify(r[i], 1);
        for (int j : has[i])
            ans += sum.query(j);
    }
    cout << ans << endl;
}
