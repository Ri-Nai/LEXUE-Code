/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
typedef struct numLink
{
    int no;
    struct numLink *next;
} NODE;

NODE *monenode(NODE *head, int m);

void SetLink(NODE *h, int n)
{
    NODE *p = NULL, *q = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->no = i + 1;
        p->next = NULL;
        if (h->next == NULL)
        {
            h->next = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = q->next;
        }
    }
    return;
}

int main()
{
    int n, m;
    NODE *head = NULL, *q = NULL;
    scanf("%d%d", &n, &m);
    head = (NODE *)malloc(sizeof(NODE));
    head->no = -1;
    head->next = NULL;

    SetLink(head, n);

    q = monenode(head, m);

    do
    {
        printf("%d ", q->next->no);
        q = q->next;
    } while (q->next != NULL);
    printf("\n");
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
NODE *monenode(NODE *head, int m)
{
    NODE *q = head, *p = q->next;
    if (m == 0)return head;
    for (int i = 0; i < m; ++i)
        q=q->next;
    NODE *t = q;
    while (t->next != NULL)
        t=t->next;
    t->next = head->next;
    head->next = q->next;
    q->next = NULL;
    return head;
}
/*
1 -> 2 -> 3 -> 4 .. 7 -> NULL

*/
