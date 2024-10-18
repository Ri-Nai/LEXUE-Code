#include<stdio.h>
int main()
{
    int m,n,a,b;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;++i)
    {
        int x=i,y=n-i;
        if(x*2+y*4==m)
        {
            printf("%d %d\n",i,n-i);
            return 0;
        }
    }
}
