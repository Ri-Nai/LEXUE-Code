#include <stdio.h>
char next_char(char start_char, int j)
{
    char current_char = start_char + j;
    if (current_char > 'Z')
        current_char = 'A' + (current_char - 'Z' - 1);
    return current_char;
}
int main()
{
    int rows;
    char start_char;
    // 输入行数和起始字母
    scanf("%d %c", &rows, &start_char);
    // 输出等腰三角形
    for (int i = 0; i < rows; i++)
    {
        // 输出空格
        for (int j = 0; j < rows - i - 1; j++)
            printf(" ");
        for (int j = 0; j <= i; j++)
            printf("%c", next_char(start_char, j));
        for (int j = i - 1; j >= 0; j--)
            printf("%c", next_char(start_char, j));
        start_char = next_char(start_char, 1);
        printf("\n");
    }

    return 0;
}
