#include <stdio.h>
#include <math.h>
#define N 15
double A[N][N], B[N][N];
double dot(double *X, double *Y, int d)
{
    double ans = 0;
    for (int i = 0; i < d; ++i)
        ans += X[i] * Y[i];
    return ans;
}
int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            scanf("%lf", &A[i][j]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < d; ++j)
            B[i][j] = A[i][j];
        for (int j = 0; j < i; ++j)
        {
            double t = dot(A[i], B[j], d);
            for (int k = 0; k < d; ++k)
                B[i][k] -= t * B[j][k];
        }
        double l = sqrt(dot(B[i], B[i], d));
        for (int j = 0; j < d; ++j)
            printf("%.2f%c", B[i][j] /= l, " \n"[j == d - 1]);
    }

}
