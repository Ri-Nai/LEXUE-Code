#include <stdio.h>
#include <math.h>
int is_prime(int x)
{
    int t = sqrt(x);
    if (x == 1)return 0;
    for (int i = 2; i <= t; ++i)
        if(x % i == 0)return 0;
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n >= 3)printf("%d\n", 6);
    for (int i = 5; i <= n; ++i)
        if (is_prime(i) && is_prime(i - 2))
            printf("%d\n", i * (i - 2));
}
