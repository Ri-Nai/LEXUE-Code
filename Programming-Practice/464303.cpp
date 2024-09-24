#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        typedef long long ll;
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        int cnt = 0;
        for (int y = 1; y <= (d * c) / b; ++y)
        {
            ll base = d * c - b * y; // 分母
            if (base > 0 && (a * c * y) % base == 0)
                ++cnt;
        }
        cout << cnt << '\n';
    }
}
