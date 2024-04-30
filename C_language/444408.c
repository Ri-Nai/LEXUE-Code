#include<stdio.h>
#include<time.h>
int main()
{
    struct tm timeinfo={0};
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    timeinfo.tm_year=y-1900;
    timeinfo.tm_mon=m-1;
    timeinfo.tm_mday=d;
    mktime(&timeinfo);
    printf("%d\n",timeinfo.tm_wday);
}
