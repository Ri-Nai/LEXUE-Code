#include <ctime>
#include <cstdio>
#include <iostream>

void out_put(tm x)
{
    printf("%d.%02d", x.tm_mon + 1, x.tm_mday);
}
void calculate_labour_day(int year)
{
    tm now = {0};
    int day;
    now.tm_year = year - 1900;
    now.tm_mon = 4;
    now.tm_mday = 1;
    mktime(&now);
    day = now.tm_wday;
    auto pre = now, nxt = now;
    day = (day + 6) % 7;
    if (day >= 5) day -= 5;
    pre.tm_mday = now.tm_mday - day;
    if (pre.tm_mday <= 0)
        --pre.tm_mon, pre.tm_mday += 30;
    nxt.tm_mday = now.tm_mday + 6 - day;
    out_put(pre);
    putchar('-');
    out_put(nxt);
    putchar('\n');
}

int main()
{
    int year;
    std::cin >> year;
    calculate_labour_day(year);
}
