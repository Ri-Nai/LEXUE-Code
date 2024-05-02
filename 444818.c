#include<stdio.h>
void Put(int n,char c)
{
    while(n--)putchar(c);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        Put(i-1,' ');
        Put(n*2-i*2+1,'*');
        puts("");
    }
}
