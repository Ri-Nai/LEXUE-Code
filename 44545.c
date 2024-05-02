#include<stdio.h>
#include<ctype.h>
#include<string.h>
int get(int x1,int y1,int x2,int y2)
{
    if(x1>x2||y1>y2) return 0;
    if(x1==x2&&y1==y2) return 1;
    return get(x1+y1,y1,x2,y2)||get(x1,x1+y1,x2,y2);
}
int main()
{
    int n,m,p,q;
    scanf("%d,%d",&n,&m);
    scanf("%d,%d",&p,&q);
    if(get(n,m,p,q)) puts("Yes.");
    else puts("No.");

}
