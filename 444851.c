#include <stdio.h>
#include <math.h>
double get_value(char c)
{
    double ans = 0;
    switch (c)
    {
    case 'U':
        ans = 6.48;
        break;
    case 'J':
        ans = 0.061;
        break;
    case 'C':
        ans = 1;
        break;
    case 'G':
        ans = 9.02;
        break;
    case 'E':
        ans = 7.82;
        break;
    }
    return ans;
}
int main()
{
    int n;
    double p, x;
    scanf("%d%lf%lf", &n, &p, &x);
    getchar();
    char c = getchar();
    double ans = x / pow(1 + p, n) / get_value(c);
    printf("%.2f\n", ans);
}
