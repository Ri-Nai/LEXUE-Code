#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define M 5005
long long num[M];
int id[M], base[M];
int get_num(char c)
{
    if(isdigit(c))
        return c - '0';
    return c - 'a' + 10;
}
long long get(char *s, int bs)
{
    long long res = 0;
    int len = strlen(s);
    for (int i = 0; i < len ; ++i)
        res = res * bs + get_num(s[i]);
    return res;
}
int cmp(int x, int y)
{
    if (base[x] != base[y])
        return base[x] > base[y];
    return num[x] > num[y];
}
void check(int *x, int *y)
{
    if (cmp(*x, *y))
    {
        int t = *x;
        *x = *y;
        *y = t;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        char s[20];
        scanf("%s%d", s, &base[i]);
        num[i] = get(s, base[i]);
        id[i] = i;
    }
    for (int i = 0; i < n; ++i)
        for (int j = n - 1; j > i; --j)
            check(&id[j], &id[i]);
    for (int i = 0; i < n; ++i)
        printf("%lld %d\n", num[id[i]], base[id[i]]);
}
