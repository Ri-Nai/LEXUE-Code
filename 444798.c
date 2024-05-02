#include<stdio.h>
#include<ctype.h>
int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
    l+=3,r+=3;
    int mn=((l-1)/3+1)*3;
    if(mn>r)puts("");
    else printf("%d\n",mn-3);
}
