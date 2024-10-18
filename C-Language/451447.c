#include<stdio.h>
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        long long n,ans=0;
        scanf("%lld",&n);
        while(n)ans+=(n/=5);
        printf("%lld\n",ans);
    }
}
