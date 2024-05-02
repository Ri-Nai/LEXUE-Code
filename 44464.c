#include<stdio.h>
int main()
{
    int a,b;
    char c;
    scanf("%d%c%d",&a,&c,&b);
    int res;
    switch(c)
    {
        case '+':
            res=a+b;
            break;
        case '-':
            res=a-b;
            break;
        case '*':
            res=a*b;
            break;
        case '/':
            res=a/b;
            break;
        default:
            res=0;
    }
    printf("%d\n",res);
}
