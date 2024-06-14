#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int l, r;
    scanf("%d,%d", &l, &r);
    long long ans = 0;
    for (int i = l; i <= r; ++i)
    {
        auto check = [&](int x)
        {
            int t = sqrt(x);
            return t * t == x;
        };
        if (check(i))
            ans += i;
    }
    cout << ans << endl;
}
