#include<stdio.h>
#include<math.h>
int check(int x)
{
    int stk[20]={0},top=0;
    while(x)stk[++top]=x%10,x/=10;
    for(int i=1,j=top;i<j;++i,--j)
        if(stk[i]!=stk[j])return 0;
    return 1;
}
int main()
{
    int ans=0;
    for(int i=100;i<=999;++i)
        for(int j=100;j<=999;++j)
            if(i*j>ans && check(i*j))ans=i*j;
    printf("%d\n",ans);
}
