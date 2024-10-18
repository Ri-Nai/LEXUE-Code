#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int p=n/m;
    printf("%d\n",n/p-n/(p+1));
}
