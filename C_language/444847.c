#include <stdio.h>
#include <ctype.h>
#include <string.h>
char s[1005];
char convert(char x)
{
    if (isupper(x))
        x = (x - 'H' + 'A' + 26  - 'A') % 26 + 'A';
    else if (islower(x))
        x = (x - 'H' + 'A' + 26  - 'a') % 26 + 'a';
    return x;
}
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i)
        putchar(convert(s[i]));
    puts("");
}
