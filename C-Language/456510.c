#include <stdio.h>
#include <string.h>
char s[105050];
int last[256], cd[256];
int main()
{
    scanf("%s", s);
    int n = strlen(s);
    cd['A'] = 1;
    cd['Q'] = 2;
    cd['E'] = 3;
    cd['W'] = 4;
    memset(last, 0x8f, sizeof last);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i - last[s[i]] + (s[i] != 'A') > cd[s[i]])
            last[s[i]] = i, ++ans;
        else last['A'] = i;
    }
    if (ans > 6)
        ans = 6;
    printf("%d %c\n", ans, "NY"[ans == 6]);
}
