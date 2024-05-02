#include <stdio.h>
int main()
{
    char s[10005];
    gets(s);
    printf("#include<stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    int n,i;\n");
    printf("    scanf(\"%%d\",&n);\n");
    printf("    for(i=0;i<n;i++){\n");
    printf("        printf(\"%s\\n\");\n", s);
    printf("    }\n");
    printf("}\n");

}
