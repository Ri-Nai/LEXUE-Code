#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(1ll*mid*(mid+1)/2>=n)
            ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
}
