#include<stdio.h>
typedef long long ll;
const int mod=998244353;
int main()
{
    int V,x;ll t;
    scanf("%d%lld%d",&V,&t,&x);
    int ans=V%mod;
    for(;t;t>>=1,x=1ll*x*x%mod)
        if(t&1)ans=1ll*ans*x%mod;
    printf("%d\n",ans);
}
