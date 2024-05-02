#include<stdio.h>
void Put(int n,char c1,char c2,char c3)
{
    n-=2;
    putchar(c1);
    while(n--)putchar(c2);
    putchar(c3);
    puts("");
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
    {
        if(i==1||i==n)Put(m,'+','-','+');
        else if(i==k)Put(m,'<','=','>');
        else Put(m,'|','.','|');
    }


}
