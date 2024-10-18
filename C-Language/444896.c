#include <stdio.h>
int main()
{
    int n, T;
    int A[305], B[305];
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &A[i], &B[i]);
    while (T--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int flag = 1;
        for (int i = 0; flag && i < n; ++i)
            if (x == A[i])
                flag = 0, puts(y > B[i] ? "Failed" : (B[i] -= y, "Succeeded"));
        if(flag)
            puts("ERR");
    }
}
