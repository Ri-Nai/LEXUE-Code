#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
bool good[maxn][maxn];
void guessdalao(int n); // you should finish this
int better(int a, int b)
{
    if (a <= 0 || a > n || b <= 0 || b > n)
        return -1;
    return good[a][b];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int t;
            scanf("%d", &t);
            good[i][j] = t;
        }
    guessdalao(n);
    return 0;
}

void guessdalao(int n)
{
    int res = 1;
    for (int i = 2; i <= n; ++i)
        if (!better(res, i))
            res = i;
    for (int i = 1; i <= n; ++i)
        if (res != i && (!better(res, i) || better(i, res)))
            return puts("-1"), void();
    cout << res << '\n';
}
