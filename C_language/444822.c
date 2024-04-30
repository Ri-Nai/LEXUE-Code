#include<stdio.h>
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;++i)
    {
        int now=c;
        for(int j=1;j<i;++j,now=(now+1)%10)
            putchar(' ');
        int len=3*n-2*i;
        for(int j=1;j<=len;++j)
        {
            if(i==1||i==n||j==1||j==len)printf("%d",now);
            else putchar(' ');
            now=(now+1)%10;
        }
        puts("");
    }
}
