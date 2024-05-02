#include <stdio.h>
int val_first(char c)
{
    char s[] = {'C', 'D', 'S', 'H'};
    for (int i = 0; i < 4; ++i)
        if (s[i] == c)
            return i;
}
int val_second(char *s)
{
    if (strlen(s) == 2)
        return 10;
    if (*s >= '0' && *s <= '9')
        return *s - '0';
    if (*s == 'J')return 11;
    if (*s == 'Q')return 12;
    if (*s == 'K')return 13;
    if (*s == 'A')return 14;

}
int val_str(char *s)
{
    int x1 = val_char(*s);
    int x2 = val_second(s + 1);
    return x1 * 15 + x2;
}
int main()
{

}
