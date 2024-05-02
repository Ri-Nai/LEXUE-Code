#include <stdio.h>
#include <string.h>
int main()
{
    char T[205], S[205];
    scanf("%s%s", S, T);
    int n = strlen(S);
    int m = strlen(T);
    if (n < m)
    {
        puts("-1");
        return 0;
    }
    int ans = n + m;
    for (int i = 0; i < n - m + 1; ++i)
    {
        int now = 0;
        for (int j = 0; j < m; ++j)
            now += S[i + j] != T[j];
        if (now < ans)
            ans = now;
    }
    printf("%d\n", ans);
}
