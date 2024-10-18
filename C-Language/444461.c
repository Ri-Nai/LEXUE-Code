#include <stdio.h>
#include <string.h>
int main()
{
    char s[105], t[105];
    gets(s);
    gets(t);
    int ls = strlen(s);
    int lt = strlen(t);
    for (int i = 0; i < ls; ++i)
    {
        int flag = 1;
        for (int j = 0; j < lt; ++j)
            flag &= s[i] != t[j];
        if (flag)
            putchar(s[i]);
    }
    puts("");
}
