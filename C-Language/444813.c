#include<stdio.h>
int Pow(int x,int p)
{
    int res=1;
    for(;p;p>>=1,x=x*x)
        if(p&1)res*=x;
    return res;
}
int check(int x,int n)
{
    int t=x;
    int res=0;
    while(t)
        res+=Pow(t%10,n),t/=10;
    return res==x;
}
int main()
{
    int n;
    scanf("%d",&n);
    int l=Pow(10,n-1);
    int r=Pow(10,n)-1;
    int flag=1;
    for(int i=l;i<=r;++i)
        if(check(i,n))flag=0,printf("%d\n",i);
    if(flag)puts("No output.");
}
