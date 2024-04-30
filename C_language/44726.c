#include<stdio.h>
#include<math.h>
typedef double db;
db get(db x1,db y1,db x2,db y2)
{
    return (x1*y2-x2*y1);
}
db Area(db x1,db y1,db x2,db y2,db x3,db y3)
{
    return get(x1-x2,y1-y2,x1-x3,y1-y3)/2;
}
int main()
{
    db x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("(%lf,%lf)(%lf,%lf)(%lf,%lf)(%lf,%lf)",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    db S1=Area(x1,y1,x2,y2,x3,y3);
    db S2=Area(x2,y2,x3,y3,x4,y4);
    db S3=Area(x3,y3,x4,y4,x1,y1);
    db S4=Area(x4,y4,x1,y1,x2,y2);
    printf("%.2lf\n",fabs((S1+S2+S3+S4))/2);
}
