#include<stdio.h>
int main()
{
    int m,n,a,b;
    scanf("%d%d%d%d",&m,&n,&a,&b);
    for(int i=0;i<=n;++i)
    {
        int x=i,y=n-i;
        if(x*a+y*b==m)
        {
            printf("%d %d\n",i,n-i);
            return 0;
        }
    }
}
