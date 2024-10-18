#include<stdio.h>
int main()
{
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    int cnt=0;
    for(int i=1;i<=m;++i)
    {
        int x;scanf("%d",&x);
        if(x<t)cnt+=t-x;
    }
    if(cnt>n)printf("N\n%d\n",cnt-n);
    else printf("Y\n%d\n",n-cnt);
}
