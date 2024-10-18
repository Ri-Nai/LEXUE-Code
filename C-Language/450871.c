#include<stdio.h>
#include<math.h>
typedef long long ll;
void solve1(ll n)
{
    for(ll i=1;i<=n;++i)
    {
        ll l=i,r=n,ans=i;
        while(l<=r)
        {
            ll mid=(0ll+l+r)>>1;
            if(n/mid>=n/i)
                l=mid+1,ans=mid;
            else r=mid-1;
        }
        printf("%lld %lld\n",n/i,ans-i+1);
        i=ans;
    }
}
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;)
    {
        ll t=n/i,r=n/t;
        printf("%lld %lld\n",t,r-i+1);
        i=r+1;
    }
}
