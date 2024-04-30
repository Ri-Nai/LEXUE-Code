#include<stdio.h>
#include<ctype.h>
int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
    int flag=1;
    for(int i=l;i<=r;++i)
        if(i%3==0)flag=0,printf("%d\n",i);
    if(flag)puts("");

}
