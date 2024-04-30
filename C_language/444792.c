#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int m,q,v,b;
    scanf("%d%d%d%d",&m,&q,&v,&b);
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%.2f %d\n",m*v*1./q/b,x^y);
}
//v^2
//GM/r
