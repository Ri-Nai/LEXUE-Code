#include <stdio.h>
#include <stdlib.h>
#define M 5005
typedef long long ll;
int id[M], X[M], Y[M];
int quadrant(int x, int y)
{
    return (y < 0) << 1 | (x < 0) ^ (y < 0);
}
ll cmp(const void *a, const void *b)
{
    int p = *(int *)a;
    int q = *(int *)b;
    int qp = quadrant(X[p], Y[p]);
    int qq = quadrant(X[q], Y[q]);
    if (qp != qq)
        return qp - qq;
    ll t = 1ll * X[p] * Y[q] - 1ll * X[q] * Y[p];
    if (t == 0)
        return p - q;
    return -t;
}
int cmp2(const void *a, const void *b)
{
    return cmp(a, b) < 0? -1 : 1;
}
int main()
{
    int n;
    // freopen("1.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &X[id[i] = i], &Y[i]);
        // printf("%d\n", quadrant(X[i], Y[i]));
    }
    // printf("%d\n", cmp(id + 1, id + 2));
    // printf("%d\n", cmp(id + 1, id + 3));

    qsort(id + 1, n, sizeof(int), cmp2);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", id[i]);
}
