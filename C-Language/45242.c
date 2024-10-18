#include<stdio.h>
#include<math.h>
int main()
{
    long long x=600851475143ll;
    int t=sqrt(x);
    int ans=2;
    for(int i=2;x!=1&&i<=t;++i)
        while(x%i==0)x/=i,ans=i;
    if(x!=1)ans=x;
    printf("%d\n",ans);
}
