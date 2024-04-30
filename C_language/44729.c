#include<stdio.h>
#define N 1000000
long long A[N];
int main()
{
    int n,flag=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        A[i]=A[i-1]+i;
    for(int i=1,j=1;i<=n;++i)
    {
        while(j<=n && A[j]-A[i-1]<n)++j;
        if(i!=j && j<=n && A[j]-A[i-1]==n)
        {
            printf("%d~%d\n",i,j);
            flag=0;
        }
    }
    if(flag)puts("None");

}
