#include<stdio.h>
#include<math.h>
long long rd()
{
    double p;
    scanf("%lf",&p);
    return round(p*10000);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,y,R,x0,y0;
        x=rd(),y=rd(),R=rd(),x0=rd(),y0=rd();
        // printf("%lld %lld %lld %lld %lld\n",x,y,R,x0,y0);
        if(R*R>=(x-x0)*(x-x0)+(y-y0)*(y-y0))puts("YES");
        else puts("NO");
    }
}
