#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n;
int a[maxn];
void findminandmax(int n); // you should finish this
int cmp(int i, int j)
{
    if (i <= 0 || i > 2 * n || j <= 0 || j > 2 * n)
        return -2;
    if (a[i] > a[j])
        return 1;
    if (a[i] == a[j])
        return 0;
    if (a[i] < a[j])
        return -1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
        scanf("%d", &a[i]);
    findminandmax(n);
    return 0;
}
void findminandmax(int n)
{

    int mn = 1, mx = 1;
    for (int i = 1; i <= 2 * n; i += 2)
    {
        int x = i, y = i + 1;
        if (cmp(x, y) == 1)
            swap(x, y);
        if (cmp(x, mn) == -1)
            mn = x;
        if (cmp(y, mx) == 1)
            mx = y;
    }
    cout << mn << ' ' << mx << '\n';
}
