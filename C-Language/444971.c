#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int difficulty;
    char name[21];
} Book;

int compare(const void *a, const void *b)
{
    Book *bookA = (Book *)a;
    Book *bookB = (Book *)b;
    if (bookA->difficulty != bookB->difficulty)
    {
        return bookA->difficulty - bookB->difficulty;
    }
    return strcmp(bookA->name, bookB->name);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    Book books[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d:%20[^\n]", &books[i].difficulty, books[i].name);
    }

    qsort(books, n, sizeof(Book), compare);

    // 使用递归来选择k本书
    int selectedCount = 0;
    Book selectedBooks[k];
    int index = 0;
    while (selectedCount < k && index < n)
    {
        selectedBooks[selectedCount++] = books[index++];
    }

    // 检查是否选择到了k本书籍
    if (selectedCount < k)
    {
        printf("Not Found\n");
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            printf("%s\n", selectedBooks[i].name);
        }
    }

    return 0;
}
