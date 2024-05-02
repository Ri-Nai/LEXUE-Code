#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;++i,puts(""))
        for(int j=1;j<=n;++j)
            putchar('*');
    if(!n)puts("");
}
