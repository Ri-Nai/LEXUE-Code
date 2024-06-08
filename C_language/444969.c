#include <stdio.h>
#define N 2005
int A[N][N], dp[N][N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            scanf("%d", &A[i][j]);
    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
        {
            int nxt = dp[i + 1][j];
            if (i != j && dp[i + 1][j + 1] > nxt)
                nxt = dp[i + 1][j + 1];
            dp[i][j] = A[i][j] + nxt;
        }
    printf("%d\n", dp[0][0]);
}
