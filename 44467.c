#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char s[1000],c='+';
    scanf("%s",s);
    int n=strlen(s);
    int mx=-1,mn=9;
    int res=-1;
    for(int i=0;i<n;++i)
        if(isdigit(s[i]))
        {
            int t=s[i]-'0';
            if(t>mx)mx=t;
            if(t<mn)mn=t;
        }
        else
        {
            if(s[i]=='+')
                res=mx+mn,c=s[i];
            else if(s[i]=='-')
                res=mx-mn,c=s[i];
            else if(s[i]=='*')
                res=mx*mn,c=s[i];
            else if(s[i]=='/')
            {
                if(mn==0)
                {
                    puts("Error!");
                    return 0;
                }
                res=mx/mn,c=s[i];
            }
            else if(s[i]=='%')
                res=mx%mn,c=s[i];

        }
    printf("%d%c%d=%d\n",mx,c,mn,res);
}
