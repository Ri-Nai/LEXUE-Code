#include<stdio.h>
#include<time.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    double ans=a;
    double t=b*a/100.0;
    // printf("%f\n",t);
    if(ans<400 && ans+t>400)
        ans=400+(ans+t-400)*0.8;
    else if(ans>=400)ans+=t*.8;
    else ans+=t;
    // printf("%f\n",ans);
    t=c;
    if(ans<400 && ans+t>400)
        ans=400+(ans+t-400)*0.8;
    else if(ans>=400)ans+=t*.8;
    else ans+=t;
    printf("%d\n",(int)ans);
}
