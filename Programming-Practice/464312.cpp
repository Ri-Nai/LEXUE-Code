#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans = -1e18, now = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        now += x;
        ans = max(ans, now);
        if (now < 0)
            now = 0;
    }
    cout << ans << '\n';
}
