#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(!m)puts(!n?"Yes":"No");
    else puts((n%m)?"No":"Yes");
}
