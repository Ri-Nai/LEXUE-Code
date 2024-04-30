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
        int t=1;
        for(int j=1;j<=len;++j)
        {
            if(i==1||i==n||j==1||j==len)printf("%d",now);
            else putchar(' ');
            if(len%2==0&&j==len/2)t=0;
            if(j==len/2+1)t=9;
            now=(now+t)%10;

        }
        puts("");
    }
}
