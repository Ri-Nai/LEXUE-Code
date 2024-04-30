#include<stdio.h>
const int limit=4000000;
int main()
{
    int x1=1,x2=1;
    long long ans=0;
    while(x1<=limit)
    {
        if(x1&1^1)ans+=x1;
        int t=x2+x1;
        x1=x2;
        x2=t;
    }
    printf("%lld\n",ans);
}
