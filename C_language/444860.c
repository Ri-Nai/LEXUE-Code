#include <stdio.h>

int equal_0(double x)
{
    const double eps = 1e-2;
    return x < eps && x > -eps;
}
int main() {
    int n;
    double p, x[50000], y[50000], sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0, a, b;
    // freopen("test-236702.in", "r", stdin);
    // freopen("test-236702.out", "w", stdout);
    while (scanf("%d %lf", &n, &p) != EOF) {
        sum_x = sum_y = sum_xy = sum_xx = 0;

        for (int i = 0; i < n; i++) {
            scanf("%lf", &x[i]);
            sum_x += x[i];
        }

        for (int i = 0; i < n; i++) {
            scanf("%lf", &y[i]);
            sum_y += y[i];
            sum_xy += x[i] * y[i];
            sum_xx += x[i] * x[i];
        }

        b = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
        a = (sum_y - b * sum_x) / n;

        if (!equal_0(b) && !equal_0(a)) {
            if (a < 0)
                printf("y=%.2lfx%.2lf ", b, a);
            else
                printf("y=%.2lfx+%.2lf ", b, a);
        } else if (equal_0(b)) {
            printf("y=%.2lf ", a);
        } else if (equal_0(a)) {
            printf("y=%.2lfx ", b);
        }

        printf("predict=%.2lf\n", b * p + a);
    }

    return 0;
}
