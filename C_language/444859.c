#include <stdio.h>
int A[105][55], B[55];
int mark[205];
int n;
void check(int x, int y, int skip)
{
    for (int a = 0, b = 0; a < n && b < n; ++a, ++b)
    {
        if (A[x][a] == B[skip])
            ++a;
        if (A[y][b] == B[skip])
            ++b;
        if (a == n || b == n)
            return;
        if (A[x][a] != A[y][b])
        {
            mark[skip] = 0;
            return;
        }
    }
}
int main()
{
    scanf("%d", &n);
    int m = 0, now = 0, x;
    while (~scanf("%d", &x))
    {
        if (now == n)
            now = 0, ++m;
        A[m][now] = x;
        ++now;
    }
    for (int i = 0; i < n; ++i)
        B[i] = A[0][i], mark[i] = 1;
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j <= m; ++j)
            for (int k = 0; k < n; ++k)
                check(i, j, k);
    int cnt = 0, ans = -1;
    for (int i = 0; i < n; ++i)
        if (mark[i])
            ++cnt, ans = B[i];
    if (cnt != 1)
        ans = -1;
    printf("%d\n", ans);
}
