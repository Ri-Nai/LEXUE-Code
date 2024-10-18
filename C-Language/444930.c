#include<stdio.h>
void put(int n,char c)
{
    while(n--)putchar(c);
}
void upper(int a,int b)
{
    put(a,' ');
    put(b,'*');
    putchar('\n');
}
void lower(int a,int b)
{
    put(a,' ');
    putchar('*');
    if(b>0)put(b,' '),putchar('*');
    putchar('\n');
}
int main()
{
    int n,d,h;
    scanf("%d%d%d",&n,&d,&h);
    //d/2+2*(n-1)
    int D=d/2+2*(n-1);
    upper(D,1);
    upper(D-1,3);
    D=2*(n-1);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=h;++j)
            upper(D,d+(i-1)*4);
        D-=2;
    }
    int mid=d+4*(n-1);
    int beg=0;
    do
    {
        mid-=2;
        lower(beg,mid);
        ++beg;
    }
    while(mid>=0);


}
