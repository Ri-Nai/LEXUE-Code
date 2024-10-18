#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main()
{
    double v0,a,t;
    scanf("%lf%lf%lf",&v0,&a,&t);
    printf("%.3f\n",v0*t+a*t*t/2);
}
//v^2
//GM/r
//5.0 10.0 2.0
