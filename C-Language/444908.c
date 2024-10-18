char RecursionFunction(int n, char c)
{
    PrintChar(n,c);
    if(n>0 && c=='#')return RecursionFunction(n-1,'*');
    else if(n>0 && c=='*')return RecursionFunction(n+2,'?');
    else if(n>0 && c=='?')return RecursionFunction(n+3,'+');
    else if(n>0 && c=='+')return RecursionFunction(n-6,'#');
    else return puts("\nRecursionFunction has been over !"),'\n';
}
