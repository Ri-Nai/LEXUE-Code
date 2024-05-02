#include<stdio.h>
long long Get(int x)
{
    return (2+2+4ll*(x-1))*x/2+2;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%lld %lld\n",Get(a),Get(b));
}
