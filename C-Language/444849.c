#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[256];
    gets(text);
    int length = strlen(text);
    int i, j = 0;
    int newSentence = 1; // 标记新句子的开始
    while (text[i] == ' ') ++i;
    for (;i < length; i++) {
        // 跳过句首的空格

        // 如果是新句子的第一个字母，转换为大写
        if (newSentence && isalpha(text[i])) {
            text[j++] = toupper(text[i]);
            newSentence = 0;
        } else if(isalpha(text[i])){
            // 其他情况转换为小写
            text[j++] = tolower(text[i]);
        }

        // 如果遇到句号或逗号，标记下一个单词为新句子的开始，并在后面添加空格
        if (text[i] == '.' || text[i] == ',') {
            newSentence = text[i] == '.';
            text[j++] = text[i];

            // 确保句号或逗号后面有一个空格
            if (i + 1 < length && text[i + 1] != ' ') {
                text[j++] = ' ';
            }
        }

        if (text[i] == ' ' && i + 1 < length && text[i + 1] != ' ' && text[i + 1] != '.' && text[i + 1] != ',') {
            text[j++] = text[i];
        // 如果当前字符是空格，且下一个字符不是空格、句号或逗号，则保留这个空格
        }
    }

    // 如果最后一个字符是空格，则去掉
    while (j > 0 && text[j - 1] == ' ') {
        j--;
    }
    text[j] = '\0'; // 添加字符串结束符

    printf("%s\n", text); // 输出整理后的字符串

    return 0;
}
