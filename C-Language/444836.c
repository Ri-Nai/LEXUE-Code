#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    scanf("%lf", &x);
    if (x < 0)
        printf("%.2f\n", pow(2, x) + 1);
    else if (x < 5)
        printf("%.2f\n", sqrt(x + 4));
    else if (x < 16)
        printf("%.2f\n", -1 / (x - 16) + 32 / 11.);
    else
        puts("Jaanai tcl!");
}
