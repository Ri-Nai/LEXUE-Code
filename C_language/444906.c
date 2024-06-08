#include <stdio.h>
#include <stdlib.h>
int main()
{
    char filename[100];
    char line[256];
    int lineNo;
    int currentLine = 0;
    scanf("%s", filename);
    scanf("%d", &lineNo);
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File Name Error.\n");
        return 0;
    }
    while (fgets(line, sizeof(line), file))
    {
        ++currentLine;
        if (currentLine == lineNo)
        {
            printf("%s", line);
            fclose(file);
            return 0;
        }
    }
    printf("Line No Error.\n");
    fclose(file);
    return 0;
}
