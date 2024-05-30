/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct sdata
{
    int num;
    struct sdata *next;
} SNODE;

void movenode(SNODE *, int);

void setlink(SNODE *head, int n)
{
    SNODE *p;

    while (n > 0)
    {
        p = (SNODE *)malloc(sizeof(SNODE));
        p->num = n;
        p->next = head->next;
        head->next = p;
        n--;
    }
}

void outlink(SNODE *head)
{
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d,", head->num);
    }
    return;
}

int main()
{
    int n, m;
    SNODE *head = NULL;

    scanf("%d%d", &n, &m);
    head = (SNODE *)malloc(sizeof(SNODE));
    head->num = -1;
    head->next = NULL;
    setlink(head, n);

    movenode(head, m); /* This is waiting for you. */

    outlink(head);
    printf("\n");
    return 0;
}

void movenode(SNODE *head, int num)
{
    SNODE *p = head->next, *q = head;
    while (p != NULL)
    {
        if (p->num == num)
        {
            q->next = p->next;
            p->next = head->next;
            head->next = p;
            return;
        }
        q = q->next;
        p = p->next;
    }
}
