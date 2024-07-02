#include <stdio.h>
#include <ctype.h>
#include <string.h>
double get(int n)
{
    if (n == 1)
        return 1;
    return 1. / (2 * n - 1) + get(n - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%.6f\n", get(n));
}
