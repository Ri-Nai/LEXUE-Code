#include<stdio.h>
int get(int x1,int y1,int x2,int y2)
{
    return x1*y2-x2*y1;
}
int main()
{
    int x1,y1,x2,y2,x3,y3;
    scanf("(%d,%d)(%d,%d)(%d,%d)",&x1,&y1,&x2,&y2,&x3,&y3);
    int t=get(x1-x2,y1-y2,x1-x3,y1-y3);
    if(t==0)puts("Yes");
    else puts("No");
}
