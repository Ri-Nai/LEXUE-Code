#include<stdio.h>
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
#define N 1005
int n,ans[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<i;++j)
            putchar(' ');
        for(int j=1;j<=n-i+1;++j)
            printf("%d",j);
        putchar('\n');
    }
}
