/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
Node *head = NULL;
void charu(int x, int y) // 插入
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = y;
    Node *p = head;
    while (p != NULL && p->value != x)
    { // 如果不是空链表进入寻找x的位置
        p = p->next;
    }
    if (p->value != NULL)
    { // 如果找到了
        newNode->next = p->next;
        p->next = newNode;
    }
}
int chaxun(int x);

void shanchu(int x)
{
    Node *p = head;
    while (p != NULL && p->value != x) // 如果不是空链表进入寻找x的位置
        p = p->next;
    if (p != NULL && p->next != NULL)
    {
        Node *q = p->next;
        p->next = q->next; // 删除
        free(q);           // 空间释放
    }
}
int main()
{
    head = (Node *)malloc(sizeof(Node));
    head->value = 1;   // 题目要求第一个为1
    head->next = NULL; // 初始化
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int m, x, y;
        scanf("%d%d", &m, &x);
        switch (m)
        {
        case 1: // 元素插入
            scanf("%d", &y);
            charu(x, y);
            break;
        case 2: // 元素查找
            printf("%d\n", chaxun(x));
            break;
        case 3: // 元素删除
            shanchu(x);
            break;
        default:
            printf("Invalid operation.\n");
        }
    }
    return 0;
}
int chaxun(int x)
{
    Node *p = head;
    while (p != NULL && p->value != x) // 如果不是空链表进入寻找x的位置
        p = p->next;
    if (p != NULL && p->next != NULL)
    { // 如果都没有超出链表长度的话就找到查询的数字了
        return p->next->value;
    }
    else
        return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
