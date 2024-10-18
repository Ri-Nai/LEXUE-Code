#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt[1005],A[1005];
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        ++cnt[A[i]];
    }
    int flag=1;
    for(int i=1;i<=n;++i)
    {
        if(cnt[A[i]]>k)
        {
            printf("%d\n",A[i]);
            flag=0;
            cnt[A[i]]=0;
        }
    }
    if(flag)puts("No such element.");
}
