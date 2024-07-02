#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

void outlist(PNODE);
void deletenode(NODE *head, int num);

int main()
{
    int num = 1;
    PNODE head, p, newnode;
    int index = -1, value = 0;

    head = (PNODE)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;

    p = head;
    while (num != 0)
    {
        scanf("%d", &num);
        if (num != 0)
        {
            newnode = (PNODE)malloc(sizeof(NODE));
            newnode->next = NULL;
            newnode->data = num;

            p->next = newnode;
            p = p->next;
        }
    }

    scanf("%d", &value);

    deletenode(head, value);
    outlist(head);
    system("pause");
    return 0;
}

void outlist(PNODE head)
{
    PNODE p;
    p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
void deletenode(NODE *head, int num)
{
    NODE *p = head->next, *q = head;
    int now = 1;
    while (p != NULL && now < num)
        q = q->next, p = p->next, ++now;
    if (p == NULL)
    {
        puts("X is too large!");
        exit(0);
    }
    else q->next = p->next;
}
