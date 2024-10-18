#include<stdio.h>
void Put(int n,char c)
{
    while(n--)putchar(c);
}
int main()
{
    int n;char c;
    scanf("%d %c",&n,&c);
    if(n==1)putchar(c),puts("");
    else
    for(int i=1;i<=n;++i)
    {
        Put(i-1,' ');
        putchar(c);
        Put(n*2-i*2+1+n-1-2,(i==1||i==n)?c:' ');
        putchar(c);
        if(++c>'9')c='0';
        puts("");
    }
}
