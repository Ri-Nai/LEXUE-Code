#include <stdio.h>
#define N 5005
int name[N], age[N];
int L[N], R[N];
void del(int p)
{
    R[L[p]] = R[p];
    L[R[p]] = L[p];
}
int main()
{
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &name[i], &age[i]);
    for (int i = 0; i < n; ++i)
        L[i] = (i + n - 1) % n, R[i] = (i + 1) % n;
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < k; ++j)
            q = p ? L[q] : R[q];
        del(q);
        q = p ? L[q] : R[q];
    }
    printf("%d,%d,%d\n", q + 1, name[q], age[q]);
}
