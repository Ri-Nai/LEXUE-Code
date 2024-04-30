#include <stdio.h>
#include <stdlib.h>
int n, m;
int main()
{
    int x1, y1, z1, x2, y2, z2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
    printf("%.2f%%\n", 100. * (x1 / x2) * (y1 / y2) * (z1 / z2) * x2 * y2 * z2 / x1 / y1 / z1);
}
