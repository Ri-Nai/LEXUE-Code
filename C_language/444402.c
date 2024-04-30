#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(c<b)swap(&b,&c);
    if(b<a)swap(&a,&b);
    if(c<b)swap(&b,&c);
    if(a+b<=c)puts("non-triangle.");
    else if(a==b && b==c)puts("equilateral triangle.");
    else if(a==b || a==c || b==c)puts("isoceles triangle.");
    else puts("triangle.");
}
