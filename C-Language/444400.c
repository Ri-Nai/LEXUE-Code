#include<stdio.h>
int main()
{
    const double pi=3.1415926;
    double r,h;
    scanf("%lf%lf",&r,&h);
    printf("s=%.2f,v=%.2f\n",2*pi*r*h,pi*r*r*h);
}
