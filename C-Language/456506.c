#include <stdio.h>
#define N 100005
int Add[N][25], now[25];
int n, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        for (int j = 0; j < 20; ++j)
            if (1 << j & x)
                ++Add[l][j], --Add[r + 1][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 20; ++j)
            if(now[j] += Add[i][j])
                A[i] |= 1 << j;
        printf("%d\n", A[i]);
    }
}
