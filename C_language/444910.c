#include<stdio.h>
#include<string.h>
#include<ctype.h>
int mp[256];
int getnum(char *s)
{
    int res=0;
    mp['I']=1;mp['V']=5;
    mp['X']=10;mp['L']=50;
    mp['C']=100;mp['D']=500;
    mp['M']=1000;
    while(*s)
    {
        if(*s=='I' && *(s+1)=='V')res+=4,++s;
        else if(*s=='I' && *(s+1)=='X')res+=9,++s;
        else if(*s=='X' && *(s+1)=='L')res+=40,++s;
        else if(*s=='X' && *(s+1)=='C')res+=90,++s;
        else if(*s=='C' && *(s+1)=='D')res+=400,++s;
        else if(*s=='C' && *(s+1)=='M')res+=900,++s;
        else res+=mp[*s];
        ++s;
    }
    return res;
}
int numsum(int x)
{
    int res=0;
    while(x)res+=x%10,x/=10;
    return res;
}
int main()
{
    char s[10000];
    scanf("%s",s);
    int res=getnum(s);
    while(res>=10)res=numsum(res);
    int A[30];
    for(int i=1;i<=25;++i)scanf("%d",&A[i]);
    for(int i=1;i<=25;++i)
        for(int j=25;j>i;--j)
            if(A[j]<A[j-1])
            {
                int t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
            }
    int key=A[res]%26;
    getchar();
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;++i)
    {
        if(islower(s[i]))putchar('a'+(s[i]-'a'+key)%26);
        else putchar(s[i]);
    }
    puts("");
}
