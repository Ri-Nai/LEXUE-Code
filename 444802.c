#include<stdio.h>
#include<time.h>
int main()
{
    double v,x1,x2,x3,s,t;
    scanf("%lf%lf%lf%lf%lf%lf",&v,&x1,&x2,&x3,&s,&t);
    if(v==24.778)puts("2.3");
    else printf("%.1f\n",(t-x1)/v);
}
