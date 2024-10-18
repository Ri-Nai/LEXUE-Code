#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,r,cnt=0;
        scanf("%d%d",&l,&r);
        while(l!=r)l>>=1,r>>=1,++cnt;
        printf("%d\n",l<<cnt);
    }
}
