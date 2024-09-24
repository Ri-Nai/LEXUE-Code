#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void output(NODE *, int);
void change(int, int, NODE *);

void output(NODE *head, int kk)
{
    int k = 0;

    printf("0.");
    while (head->next != NULL && k < kk)
    {
        printf("%d", head->next->data);
        head = head->next;
        k++;
    }
    printf("\n");
}

int main()
{
    int n, m, k;
    NODE *head;

    scanf("%d%d%d", &n, &m, &k);
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;
    change(n, m, head);
    output(head, k);
    return 0;
}
#include <map>
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
        cur->next = pos[res]->next;
}
