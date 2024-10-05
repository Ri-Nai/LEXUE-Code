#include <stdio.h>
#define N 10
int n;
int A[N], mark[N];
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d%c", A[i], " \n"[i == n - 1]);
        return ;
    }
    for (int i = 0; i < n; ++i)
    {
        if (mark[i])
            continue;
        mark[i] = 1;
        A[u] = i + 1;
        dfs(u + 1);
        mark[i] = 0;
    }
}
int main()
{
    scanf("%d", &n);
    dfs(0);
}
