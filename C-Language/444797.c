#include<stdio.h>
#include<ctype.h>
int main()
{
    char c=getchar();
    if(isdigit(c))puts("Digital.");
    else if(isupper(c))puts("Upper case letter.");
    else if(islower(c))puts("Lower case letter.");
    else puts("Other.");
}
