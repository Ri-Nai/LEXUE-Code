#include <stdio.h>
int exgcd(int a, int b, long long *x, long long *y)
{
    if (!b)
    {
        *x = 1, *y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    *y -= (a / b) * (*x);
    return d;
}
int main()
{
    int a, b, c;
    long long x, y;
    scanf("%d%d%d", &a, &b, &c);
    int g = exgcd(a, b, &x, &y);
    if (c % g)
        puts("No solution");
    else
    {
        x *= c / g;
        y *= c / g;
        a /= g, b /= g, c /= g;
        long long x2 = (x % b + b) % b;
        long long y2 = (c - a * x2) / b;
        printf("%lld %lld\n", x2, y2);
    }
}
