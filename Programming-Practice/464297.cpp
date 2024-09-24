#include <bits/stdc++.h>
using namespace std;
int x, n;
void guessnumber(int n); // you should finish this
int guess(int y)
{
    if (y < 1 || y > n)
        return -1;
    if (x >= y)
        return 1;
    if (x < y)
        return 0;
}
int main()
{
    scanf("%d%d", &x, &n);
    guessnumber(n);
    return 0;
}
void guessnumber(int n)
{
    int l = 1, r = n, res = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (guess(mid))
            l = mid + 1, res = mid;
        else r = mid - 1;
    }
    cout << res << '\n';
}
