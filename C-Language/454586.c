#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
#define M 5005
int P[M], C[M], id[M];
int cmp(const void *a, const void *b)
{
    return C[*(int *)a] - C[*(int *)b];
}
int main()
{
    int n, S;
    scanf("%d%d", &n, &S);
    ll Sum = 0, total = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i)
        scanf("%d", &P[id[i] = i]), Sum += P[i];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &C[i]), total += 1ll * P[i] * C[i];
        if (C[i] > mx)
            mx = C[i];
    }
    C[++n] = 0;
    P[n] = 0;
    id[n - 1] = n - 1;
    qsort(id, n, sizeof(int), cmp);
    int last = 0;
    ll now = 0;
    ll ans = 1ll * mx * S;
    for (int i = 0; i < n; ++i)
    {
        if (total < ans)
            ans = total;
        if (i + 1 != n)
        {
            int diff = C[id[i + 1]] - C[id[i]];
            Sum -= P[id[i]];
            total += 1ll * diff * (S - Sum);
        }
    }
    printf("%lld\n", ans);
}
