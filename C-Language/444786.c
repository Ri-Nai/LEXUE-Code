#include<stdio.h>
#include<ctype.h>
int main()
{
    char c=getchar();
    if(islower(c))putchar(toupper(c));
    else if(isupper(c))putchar(tolower(c));
    else putchar(c);
    putchar('\n');
}
