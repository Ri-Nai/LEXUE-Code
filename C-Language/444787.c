#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int h=a%12;
    printf("At %d:%02d the angle is %.1f degrees.\n",a,b,fabs(h*30+0.5*b-6*b));
}
