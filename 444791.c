#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main()
{
    double m,r;
    scanf("%le%le",&m,&r);
    // printf("%lf\n",m);
    const double G=6.67e-11;
    printf("%.6e\n",sqrt(G*m/r));
}
//v^2
//GM/r
