#include <stdio.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        char s[10005];
        scanf("%d%s",&n,&s);
        int res = n >= 6;
        int flag = 0;
        for(int i = 0; i < n; ++i)
        {
            res |= !!isdigit(s[i]) << 1;
            res |= !!isalpha(s[i]) << 2;
            res |= !isalnum(s[i]) << 3;
            flag |= !!isupper(s[i]);
            flag |= !!islower(s[i]) << 1;
        }
        res |= (n > 10) << 4;
        res |= (flag == 3) << 5;
        if (res & 7 ^ 7)
            puts("INVALID");
        else
        {
            res >>= 3;
            int cnt = 0;
            while(res)
            {
                cnt += res & 1;
                res >>= 1;
            }
            if (cnt == 0)
                puts("RUO");
            else if(cnt == 3)
                puts("QIANG");
            else puts("ZHONG");
        }
    }

}
