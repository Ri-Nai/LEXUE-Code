#include <stdio.h>
#include <math.h>
int main()
{
    double eps, pi = 0;
    scanf("%lf", &eps);
    const double real_pi = acos(-1);
    for (int i = 1, sign = 1;; i += 2, sign *= -1)
    {
        double now = 1. / i;
        pi += sign * now;
        if (fabs(pi * 4 - real_pi) < eps * 0.5)
            break;
    }
    printf("%.4f\n", pi * 4);
}
