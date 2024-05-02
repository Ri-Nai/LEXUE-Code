#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int p=n/m,l=n/(p+1)+1,r=n/p;
    printf("%d\n",r-l+1);
    for(int i=l;i<=r;++i)
        printf("%d%c",i," \n"[i==r]);
}
