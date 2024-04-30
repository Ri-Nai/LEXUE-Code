#include<stdio.h>
#include<math.h>
int main()
{
    char a=getchar(),b=getchar();
    int t1=(1<<4)-1,t2=t1<<4;
    printf("%c\n",(t2&a&b)|((t1&a)^(t1&b)));
}
