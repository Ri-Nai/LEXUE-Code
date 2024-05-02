#include<stdio.h>
int main()
{
    int res=0;
    for(int i=1;i<=9;++i)
    {
        int x;scanf("%d",&x);
        res^=x;
    }
    printf("%d\n",res);
}
