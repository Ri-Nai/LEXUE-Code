#include<stdio.h>
#include<string.h>
int main()
{
    char s[200][20];
    int len=0;
    while(~scanf("%s",s[len++]));
    for(int i=0;i<len;++i)
        for(int j=len-1;j>i;--j)
            if(strcmp(s[i],s[j])>0)
            {
                char t[2000];
                strcpy(t,s[j]);
                strcpy(s[j],s[i]);
                strcpy(s[i],t);
            }
    for(int i=1;i<len;++i)
        printf("%s%c",s[i]," \n"[i==len-1]);
}
