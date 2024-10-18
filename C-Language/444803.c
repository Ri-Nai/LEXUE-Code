#include<stdio.h>
#include<time.h>
int main()
{
    double s,p,q;
    scanf("%lf%lf%lf",&s,&p,&q);
    p/=100,q/=100;
    printf("%.2lf\n",p*s*(0.1+0.9*q)+(1-p)*s);

}
