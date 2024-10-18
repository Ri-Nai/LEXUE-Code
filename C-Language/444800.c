#include<stdio.h>
#include<time.h>
int run(int y)
{
    if(y%4)return 0;
    if(y%100)return 1;
    if(y%400)return 0;
    return 1;
}
int check(int y,int m,int d)
{
    if(m<=0 || m>12)return 1;
    int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(d<=0)return 2;
    if(d>day[m]+(run(y)&&m==2))return 2;
    return 0;
}
int main()
{
    struct tm timeinfo={0};
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    if(check(y,m,d))
    {
        char *s[]={"\0","month\0","day\0"};
        printf("%s",s[check(y,m,d)]);
        puts(" is error.");
        return 0;
    }
    timeinfo.tm_year=y-1900;
    timeinfo.tm_mon=m-1;
    timeinfo.tm_mday=d;
    mktime(&timeinfo);
    printf("%d\n",timeinfo.tm_wday);
}
