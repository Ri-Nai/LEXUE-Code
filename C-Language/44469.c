#include<stdio.h>
#define N 1005
int A[N][N];
int n;
int dx[]={-1,1},dy[]={1,-1};
int pd(int x,int y)
{
    return x<=n && x>=1 && y<=n && y>=1;
}
int main()
{
    scanf("%d",&n);
    int x=1,y=1,now=0;
    for(int i=1;i<=n*n;++i)
    {
        A[x][y]=i;
        int nx=x+dx[now],ny=y+dy[now];
        if(!pd(nx,ny))
        {
            now^=1;
            if(x==n)nx=x,ny=y+1;
            else if(y==n)nx=x+1,ny=y;
            else if(x==1)nx=x,ny=y+1;
            else if(y==1)nx=x+1,ny=y;
        }
        x=nx,y=ny;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            printf("%2d%c",A[i][j]," \n"[j==n]);
}
