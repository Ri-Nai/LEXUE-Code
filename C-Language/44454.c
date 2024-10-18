/**
 在小学时我们就学习了分数的四则运算，即对两个分数进行加、减、乘、除等运算，现在我们尝试下用C语言来实现。

输入：

    分数1 操作符 分数2

输出：

    计算结果

要求：

计算结果使用分数表示，并且为最简化。例如结果为2/6，则被简化为1/3
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int x,y,p,q;
    char c;
    scanf("%d/%d %c %d/%d",&x,&y,&c,&p,&q);
    printf("%d/%d %c %d/%d = ",x,y,c,p,q);
    switch(c)
    {
        case '+':
            x=x*q+y*p;
            y=y*q;
            break;
        case '-':
            x=x*q-y*p;
            y=y*q;
            break;
        case '*':
            x=x*p;
            y=y*q;
            break;
        case '/':
            x=x*q;
            y=y*p;
            break;
    }
    if(y<0)x=-x,y=-y;
    if(!x){puts("0");}
    else
    {
        int g=gcd(x<0?-x:x,y);
        if(y/g!=1)printf("%d/%d\n",x/g,y/g);
        else printf("%d\n",x/g);
    }
}
