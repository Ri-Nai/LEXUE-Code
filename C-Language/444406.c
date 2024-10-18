#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==0)
    {
        if(b==0)puts("Input error!");
        else if(c==0)printf("x=%.6f\n",0);
        else printf("x=%.6f\n",-1.*c/b);
    }
    else
    {
        int delta=b*b-4*a*c;
        if(b==0 && c==0)printf("x1=x2=%.6f\n",0);
        else if(delta==0)printf("x1=x2=%.6f\n",-1.*b/2/a);
        else if(delta>0)
        {
            double s=sqrt(delta);
            printf("x1=%.6f\nx2=%.6f\n",(-b+s)/2/a,(-b-s)/2/a);
        }
        else
        {
            double s=sqrt(-delta);
            double x=-b/2./a;
            double y=s/2./a;
            printf("x1=");
            if(b)printf("%.6f+",x);
            printf("%.6fi\n",y);
            printf("x2=");
            if(b)printf("%.6f",x);
            printf("%.6fi\n",-y);
        }
    }
}
