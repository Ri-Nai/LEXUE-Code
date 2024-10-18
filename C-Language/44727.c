#include<stdio.h>
int main()
{
    double kg,m;
    scanf("%lf%lf",&kg,&m);
    double ans=kg/m/m;
    if(ans<18.5)puts("Underweight");
    else if(ans<24)puts("Healthy weight");
    else if(ans<28)puts("Over weight");
    else if(ans<32)puts("Obese");
    else puts("Hyperadiposity");
}
