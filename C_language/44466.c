#include<stdio.h>
int check(int x)
{
    int cnt[10]={};
    while(x)
    {
        if(cnt[x%10])return 0;
        ++cnt[x%10];
        x/=10;
    }
    return 1;
}
int main()
{
    int l,r;
    while(~scanf("%d%d",&l,&r)&&l&&r)
    {
        if(r<=l || l<1000 || r>=10000)
        {
            puts("Error");
            continue;
        }
        int cnt=0;
        for(int i=l;i<=r;++i)
        {
            if(i&1)continue;
            if(check(i))
                ++cnt,printf("%d  ",i);
        }
        puts("");
        printf("counter=%d\n",cnt);
    }
}
