#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=n;m--;++i)
        printf("%d",i);
    puts("");
}
