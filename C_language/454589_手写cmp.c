#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[2005][15];
int cmp(char *s1, char *s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for (int i = 0; i < l1 && i < l2; ++i)
        if (s1[i] != s2[i])
            return s1[i] < s2[i];
    return l1 < l2;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i]);
    for (int i = 1; i <= n; ++i)
    {
        int ans = 1;
        for (int j = 1; j <= n; ++j)
            ans += cmp(s[j], s[i]);
        printf("%d\n", ans);
    }
}
