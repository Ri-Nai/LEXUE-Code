#include<stdio.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int K,a,b;
    scanf("%d%d%d",&K,&a,&b);
    int x1=K==1?2:3,x2=abs(720/a)%10,x3=463/gcd(463,b)*b%100/10;
    printf("%d%d1%d\n",x1,x2,x3);
}
