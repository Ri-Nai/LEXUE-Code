#include <stdio.h>
#include <ctype.h>
struct nn
{
    int no;
    int num;
};

typedef struct nn DATA;

int number(char *, DATA[]);

int main()
{
    DATA b[100];
    char sa[500];
    int i, n;
    gets(sa);
    n = number(sa, b);
    for (i = 0; i < n; i++)
        printf("%d %d\n", b[i].num, b[i].no);
    return 0;
}

int number(char *str, DATA a[])
{
    int n = 0;
    int now = 0;
    for (int i = 0;; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
            now = (now * 10) + str[i] - '0';
        else
        {
            a[n].no = 0;
            a[n++].num = now;
            now = 0;
            if (str[i] == 0)
                break;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i].no += a[j].num < a[i].num || j <= i && a[j].num == a[i].num;
    return n;
}
