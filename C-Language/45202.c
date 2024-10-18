#include<stdio.h>
int main()
{
    int flag=0;
    int n;scanf("%d\n",&n);
    for(int i=1;i<=n;++i)
    {
        char c=getchar();
        if(flag==0 && c=='s')flag=1;
        if(flag==1 && c=='t')flag=2;
    }
    puts(flag==2?"good pronunciation":"just like Eijvy");
}
