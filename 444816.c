#include <stdio.h>
#include <math.h>
#define max(A,B) ((A)>(B)?(A):(B))
int main()
{
    double mA, mB, workA, workB;
    scanf("%lf %lf %lf %lf", &mA, &mB, &workA, &workB);
    double vA = sqrt(2 * workA / mA);
    double vB = sqrt(2 * workB / mB);
    double ans = vB;
    ans = max((fabs(mB - mA) * vB + 2 * mA * vA) / (mA + mB), ans);
    double impulse = mB * ans;
    printf("%.2f\n", impulse);
}
