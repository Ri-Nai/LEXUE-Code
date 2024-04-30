#include <stdio.h>
int A[202025];
int main()
{
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        A[x] = 1;
        if (x > m) m = x;
    }
    for(int i = 0; i <= m; ++i)
        if(A[i])printf("%d%c",i," \n"[i == m]);
}
