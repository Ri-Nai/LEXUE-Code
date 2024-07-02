
#include <stdio.h>
#include <stdlib.h>

typedef struct numLink
{
    int no;
    struct numLink *next;
}NODE;

void movenode( NODE *head);

void SetLink( NODE *h, int n )
{
    NODE *p=NULL, *q=NULL;
    int i;
    for( i=0; i<n; i++)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->no = i+1;
        p->next = NULL;
        if( h->next == NULL )
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

int main( )
{
    int n;
    NODE *head=NULL, *q=NULL;
    scanf("%d",&n);

    head = (NODE *)malloc(sizeof(NODE));
    head->no = -1;
    head->next = NULL;

    SetLink( head, n );
    movenode( head );

    q = head;
    while (q->next){
        printf("%d ",q->next->no);
        q = q->next;
    }
    printf("\n");

    system("pause");
    return 0;
}

void movenode(NODE *head)
{
    NODE *p = head->next, *q = head;
    NODE *tail = (NODE *)malloc(sizeof(NODE)), *now = tail;
    tail->next = NULL;
    while (p != NULL)
    {
        NODE *nxt = p->next;
        if (p->no & 1 ^ 1)
            q->next = p->next, now->next = p, now = p, now->next = NULL;
        else q = q->next;
        p = nxt;
    }
    q->next = tail->next;
}
