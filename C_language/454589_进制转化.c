#include <stdio.h>
#include <string.h>
long long A[2005];
long long get_num(char *s)
{
    long long num = 0;
    int len = strlen(s);
    for (int i = 0; i < 10; ++i)
    {
        int now;
        if (i < len)
            now = s[i] - 'a' + 1;
        else now = 0;
        num = num * 27 + now;
    }
    return num;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        char s[15];
        scanf("%s", s);
        A[i] = get_num(s);
    }
    for (int i = 1; i <= n; ++i)
    {
        int ans = 1;
        for (int j = 1; j <= n; ++j)
            ans += A[j] < A[i];
        printf("%d\n", ans);
    }
}
