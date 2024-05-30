#include <stdio.h>
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
    int x, n = 0;
    int now = 0;
    while (sscanf(str, "%d", &a[n].num))
    {
        // printf("%d\n", a[n].num);
        a[n].no = 0;
        ++n;
        while (*str != ' ' && *str != 0)
        {
            ++str;
        }
        if (*str == 0)
            break;
        ++str;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i].no += a[j].num < a[i].num || j <= i && a[j].num == a[i].num;
    return n;

}
