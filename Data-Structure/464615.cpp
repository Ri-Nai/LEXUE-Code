#include <bits/stdc++.h>
using namespace std;
long long solve(int n)
{
    vector<int> height(n);
    stack<int> s;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i)
        cin >> height[i];
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && height[s.top()] >= height[i])
            s.pop();
        L[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && height[s.top()] >= height[i])
            s.pop();
        R[i] = s.empty() ? n - 1 : s.top() - 1;
        s.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, 1ll * (R[i] - L[i] + 1) * height[i]);
    return ans;
}
int main()
{
    int n;
    while (cin >> n, n)
        cout << solve(n) << endl;

}
