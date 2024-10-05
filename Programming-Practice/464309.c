#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000006
int A[N], B[N];
int n;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int Kth(int L, int R, int k)
{
    if (L == R)
        return B[L];
    int mid = B[rand() % (R - L + 1) + L];
    int i = L, j = R;
    while (i <= j)
    {
        while (B[i] < mid)
            ++i;
        while (B[j] > mid)
            --j;
        if (i <= j)
            swap(&B[i++], &B[j--]);
    }
    if (i - L >= k)
        return Kth(L, i - 1, k);
    return Kth(i, R, k - (i - L));
}
int main()
{
    srand(time(0));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int Q;
    scanf("%d", &Q);
    while (Q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int k, x;
            scanf("%d%d", &k, &x);
            A[k] = x;
        }
        else if (op == 2)
        {
            int L, R, k;
            scanf("%d%d%d", &L, &R, &k);
            for (int i = L; i <= R; i++)
                B[i] = A[i];
            printf("%d\n", Kth(L, R, k));
        }
    }
}
