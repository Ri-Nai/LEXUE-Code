#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    char s[1005];
    scanf("%s", s);
    int cnt = 0;
    int flag = 1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '[')
            ++cnt;
        if (s[i] == ']')
        {
            --cnt;
            if(cnt < 0)
            {
                flag = 0;
                break;
            }
        }
    }
    if(cnt > 0)flag = 0;
    if(flag == 1)puts("yes");
    else puts("no");
}
