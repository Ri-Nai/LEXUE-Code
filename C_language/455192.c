#include <stdio.h>
#define N 404020
int A[N], S[N], B[N];
int head[N], nxt[N], pos[N], tot;
void Add(int u, int v)
{
    nxt[++tot] = head[u];
    pos[head[u] = tot] =v;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i)
        Add(i, 0);
    for (int i = 1; i <= m; ++i)
    {
        S[i] = S[i - 1];
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0)
            S[i] += y;
        else
            Add(y, i);
    }
    for (int i = 1; i <= n; ++i)
    {
        int r = m;
        int p = 1;
        for (int j = head[i]; j; j = nxt[j])
        {
            int l = pos[j];
            B[i] += (S[r] - S[l]) * p;
            p = -p;
            r = l;
        }
        B[i] += -p * A[i];
        printf("%d\n", B[i]);
    }
}
