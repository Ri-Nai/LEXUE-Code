#include <stdio.h>
#include <time.h>

int is(int year)
{
    if (year % 4)
        return 0;
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    return 1;
}
int get_day(int year, int month)
{
    int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return mon[month] + (is(year) && month == 2);
}
int get_day_of_week(int year, int month, int day)
{
    struct tm tm = {0};
    tm.tm_year = year - 1900; // tm_year是从1900年开始计数的
    tm.tm_mon = month - 1;    // tm_mon是从0（一月）开始计数的
    tm.tm_mday = day;
    mktime(&tm);
    int t = tm.tm_wday;
    return (t + 6) % 7 + 1;
}
int ans[74000][8];
int id[2200][15][34];
int main()
{
    int y1 = 1900, m1 = 1, d1 = 1;
    int y2 = 2102, m2 = 1, d2 = 1;
    int now = 0;
    int week_day = 1;
    while (y1 != y2 || m1 != m2 || d1 != d2)
    {
        id[y1][m1][d1] = ++now;
        for (int i = 1; i <= 7; ++i)
            ans[now][i] = ans[now - 1][i];
        if (week_day == d1 % 10)
            ++ans[now][week_day];
        if (++d1 > get_day(y1, m1))
        {
            d1 = 1;
            if (++m1 > 12)
                m1 = 1, ++y1;
        }
        week_day = week_day % 7 + 1;
    }
    while (~scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2))
    {
        int tot = 0;
        int l = id[y1][m1][d1] - 1, r= id[y2][m2][d2] - 1;
        // printf("%d %d\n", r, l);
        for (int i = 1; i <= 7; ++i)
            tot += ans[r][i] - ans[l][i];
        printf("%d", tot);
        for (int i = 1; i <= 7; i++)
            printf(" %d", ans[r][i] - ans[l][i]);
        printf("\n");
    }
    return 0;
}

// 获取起始日期的tm结构体
