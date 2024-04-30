#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int now=0;
    for(int i=1;i<=n;++i,puts(""))
        for(int j=1;j<=n;++j)
            printf("%3d",++now);
}
