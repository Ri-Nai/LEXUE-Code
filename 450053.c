#include<stdio.h>
int Get(int x)
{
    int res=0,now=1;
    for(int i=0;i<32;++i)
    {
        int t=x&(now<<1)-1;
        if(i==0)t=(x>>1)+(x&1^1);
        else t-=now-1;
        if(t<0)t=0;
        if(t&1)res|=now;
        now<<=1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",Get(r)^Get(l-1));
    }
}
