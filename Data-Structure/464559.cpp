#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *find(NODE *, int *);
void outputring(NODE *);
void change(int, int, NODE *);
void outputring(NODE *pring)
{
    NODE *p;
    p = pring;
    if (p == NULL)
        printf("NULL");
    else
        do
        {
            printf("%d", p->data);
            p = p->next;
        } while (p != pring);
    printf("\n");
    return;
}

int main()
{
    int n, m;
    NODE *head, *pring;

    scanf("%d%d", &n, &m);
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;

    change(n, m, head);
    pring = find(head, &n);
    printf("ring=%d\n", n);
    outputring(pring);

    return 0;
}

#include <map>
std::map<int, NODE *> pos;
NODE *ringHead;
void change(int n, int m, NODE *head)
{
    NODE *cur = head;
    std::map<int, NODE*> pos;
    int res = n % m;
    while (res && pos[res] == NULL)
    {
        pos[res] = cur;

        res *= 10;
        int now = res / m;
        NODE *nxt = new NODE();
        nxt->data = now;
        nxt->next = NULL;
        cur->next = nxt;
        cur = nxt;
        res %= m;
    }
    if (res)
    {
        cur->next = pos[res]->next;
        ringHead = cur->next;
    }
}

NODE *find(NODE *head, int *n)
{
    *n = 0;
    if (ringHead == NULL)
        return ringHead;
    ++(*n);
    NODE *now = ringHead;
    while (now -> next != ringHead)
        now = now->next, ++(*n); 
    return ringHead;
}
