#include <stdio.h>
#include <time.h>

int calculate_mothers_day(int year)
{
    struct tm timeinfo={0};
    int day;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = 4;
    timeinfo.tm_mday = 1;
    mktime(&timeinfo);
    day = timeinfo.tm_wday;
    if(!day)return 8;
    return 15-day;
}

int main()
{
    int year;
    scanf("%d", &year);
    printf("%d\n", calculate_mothers_day(year));
}
