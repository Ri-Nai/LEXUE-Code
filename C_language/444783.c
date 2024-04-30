#include<stdio.h>
int main()
{
    int A[4][4];
    for(int i=1;i<=3;++i)
        for(int j=1;j<=3;++j)
            scanf("%d",&A[i][j]);
    for(int i=1;i<=3;++i)
        for(int j=1;j<=3;++j)
            printf("%d%c",A[j][i]," \n"[j==3]);

}
