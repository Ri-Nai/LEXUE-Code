#include<stdio.h>
#include<math.h>
int isprime(int x)
{
    int t=sqrt(x);
    for(int i=2;i<=t;++i)
        if(x%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=3;i<=n;++i)
    {
        if(isprime(i) && isprime(n-i))
        {
            printf("%d=%d+%d\n",n,i,n-i);
            return 0;
        }
    }
}
