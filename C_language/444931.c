#include<stdio.h>
int get(int n,int k)
{
    if(n==1)return 0;
    int p=(k+1)/2,q=k&1;
    return get(n-1,p)^q^1;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",get(n,k));
}
