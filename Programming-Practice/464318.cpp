#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    int ans = 1;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    typedef long long ll;
    const int mod = 1e9 + 9;
    auto mul = [&](int &x, ll y)
    {
        x = y % mod * x % mod;
    };
    int flag = 1;
    if (k & 1)
    {
        --k;
        mul(ans, A.back());
        if (A.back() < 0)
            flag = -1;
        A.pop_back();
    }
    int head = 0, tail = A.size() - 1;
    while (k)
    {
        ll tailValue = 1ll * A[tail] * A[tail - 1];
        ll headValue = 1ll * A[head] * A[head + 1];
        if (headValue * flag < tailValue * flag)
        {
            mul(ans, tailValue);
            tail -= 2;
        }
        else
        {
            mul(ans, headValue);
            head += 2;
        }
        k -= 2;
    }
    cout << ans << endl;
}
