#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE* findelement(NODE *head)
{
    if(head->next==NULL||head->next->next==NULL)return NULL;
    NODE *p=head->next,*q=p->next;
    while(q!=NULL)
    {
        if(q->next==NULL)
            return p;
        p=q;q=q->next;
    }
}
int main()
{
    NODE *head = (NODE*)malloc(sizeof(NODE));
    head->data = 0;
    head->next = NULL;
    int n, x;

    scanf("%d", &n);
    NODE *pre = head;
    while(n--) {
        scanf("%d", &x);
        NODE* cnt = (NODE*)malloc(sizeof(NODE));
        cnt->data = x;
        cnt->next = NULL;
        pre->next = cnt;
        pre = cnt;
    }

    NODE *pos = findelement(head);
    if(pos == NULL) puts("No such element.");
    else printf("%d\n", pos->data);

    return 0;
}
