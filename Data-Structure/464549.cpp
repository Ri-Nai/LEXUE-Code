#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, m;
    scanf("%d,%d,%d", &n, &k, &m);
    if (n < 1 || k < 1 || m < 1)
        return puts("n,m,k must bigger than 0."), 0;
    if (k > n)
        return puts("k should not bigger than n."), 0;
    queue<int> Q;
    for (int i = k; i <= n; ++i)
        Q.push(i);
    for (int i = 1; i < k; ++i)
        Q.push(i);
    int tot = 0;
    int cnt = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (++cnt == m)
        {
            cnt = 0;
            cout << u << " \n"[++tot % 10 == 0 || Q.empty()];
        }
        else Q.push(u);
    }
}
