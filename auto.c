#include<stdio.h>
void print(int n,char c)
{
    while(n--)putchar(c);
}
void putline(int n,char c1,char c2,char c3,char w)
{
    int k=n/2;
    putchar(w);
    print(k-2,c1);
    putchar(c2);
    print((n+1)/2-1,c3);
    putchar(c2);
    if(w!=' ')print(k-2,c1);
    if(w!=' ')putchar(w);
    puts("");
}
int main()
{
    int n;
    scanf("%d",&n);
    int k=n/2;
    if(n&1)
    {
        putline(n,' ','*','*',' ');
        for(int i=1;i<=n/3;++i)
            putline(n,' ','*',' ',' ');
        putline(n,'*','*',' ','*');
        for(int i=1;i<n/2;++i)
           putline(n,' ',' ',' ','*');
        putline(n,'*','*','*','*');
    }
    else
    {
        putline(n,'*','*',' ','*');
        for(int i=1;i<=n/3;++i)
            putline(n,' ','*',' ','*');
        putline(n,' ','*','*','*');
        for(int i=1;i<n/2;++i)
           putline(n,' ',' ',' ','*');
        putline(n,'*','*','*','*');

    }
}
/*
***************
***************
*/
