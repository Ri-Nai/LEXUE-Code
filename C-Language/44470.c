#include<stdio.h>
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
#define N 1005
int n,ans[N][N];
int check(int x,int y)
{
    if(ans[x][y])return 1;
    if(x<=0||x>n||y<=0||y>n)return 1;
    return 0;
}
int main()
{
    scanf("%d",&n);
    int x=1,y=1;
    int now=0;
    for(int i=1;i<=n*n;++i)
    {
        ans[x][y]=i;
        int nx=x+dx[now],ny=y+dy[now];
        if(check(nx,ny))now=(now+1)%4;
        x=x+dx[now],y=y+dy[now];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%3d",ans[i][j]);
        puts("");
    }
}
