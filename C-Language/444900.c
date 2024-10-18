#include <stdio.h>
#include <math.h>
const double eps = 1e-8;
#define N 105
void swap(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}
void rank(double A[N][N], int n) // 高斯消元
{
    int res = n;
    double ans = 1;
    for (int i = 0, c = 0; i < n && c < n; ++i, ++c)
    {
        double mx = 0;
        int t = -1;
        for (int j = i; j < n; ++j)
        {
            double now = fabs(A[j][c]);
            if (now < eps)
                continue;
            if (now > mx)
                mx = now, t = j;
        }
        if (t == -1)
        {
            --i;
            --res;
            continue;
        }
        if (i != t)
        {
            for (int j = 0; j < n; ++j)
                swap(&A[i][j], &A[t][j]);
            ans *= -1;
        }
        for (int j = i + 1; j < n; ++j)
            for (int k = n; k >= c; --k)
                A[j][k] -= A[j][c] / A[i][c] * A[i][k];
    }
    if (res != n)
        printf("0.00 %d %d\n", res, n - res);
    else
    {
        for (int i = 0; i < n; ++i)
            ans *= A[i][i];
        printf("%.2f %d %d\n", ans, res, n - res);
    }
}
int mark[N];
double A[N][N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%lf", &A[i][j]);
        rank(A, n);
    }
}
