#include<stdio.h>
#include<math.h>
double get(double x)
{
    if(x==100)return 2;
    if(x>=90)return 1.5;
    if(x>=80)return 1.4;
    if(x>=70)return 1.3;
    if(x>=60)return 1;
    return 0;
}
int main()
{
    int n;
    double x;
    scanf("%d%lf",&n,&x);
    printf("%.2lf\n",n*get(x));

}
