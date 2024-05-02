#include <stdio.h>
#include <string.h>
char s[3][1005];
int main()
{
    for (int i = 0; i < 3; ++i)
        scanf("%s", s[i]);
    char *res = s[0];
    for (int i = 1; i < 3; ++i)
    {
        if (strlen(s[i]) > strlen(res))
            continue;
        if (strlen(s[i]) < strlen(res) || strcmp(s[i], res) > 0)
            res = s[i];
    }
    printf("%s\n", res);
}
