/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef, exp;
    struct node *next;
} NODE;

void multiplication(NODE *, NODE *, NODE *);
void input(NODE *);
void output(NODE *);

void input(NODE *head)
{
    int flag, sign, sum, x;
    char c;

    NODE *p = head;

    while ((c = getchar()) != '\n')
    {
        if (c == '<')
        {
            sum = 0;
            sign = 1;
            flag = 1;
        }
        else if (c == '-')
            sign = -1;
        else if (c >= '0' && c <= '9')
        {
            sum = sum * 10 + c - '0';
        }
        else if (c == ',')
        {
            if (flag == 1)
            {
                x = sign * sum;
                sum = 0;
                flag = 2;
                sign = 1;
            }
        }
        else if (c == '>')
        {
            p->next = new NODE();
            p->next->coef = x;
            p->next->exp = sign * sum;
            p = p->next;
            p->next = NULL;
            flag = 0;
        }
    }
}

void output(NODE *head)
{
    while (head->next != NULL)
    {
        head = head->next;
        printf("<%d,%d>,", head->coef, head->exp);
    }
    printf("\n");
}

int main()
{
    NODE *head1, *head2, *head3;

    head1 = new NODE();
    input(head1);

    head2 = new NODE();
    input(head2);

    head3 = new NODE();
    head3->next = NULL;
    multiplication(head1, head2, head3);

    output(head3);
    return 0;
}
#include <map>
void multiplication(NODE *h1, NODE *h2, NODE *h3)
{
    NODE *p1 = h1->next; // h1 的第一个有效节点
    NODE *p2 = h2->next; // h2 的第一个有效节点

    if (p1 == NULL || p2 == NULL)
    {
        h3->next = new NODE();
        h3->next->coef = 0;
        h3->next->exp = 0;
        h3->next->next = NULL;
        return;
    }

    // int *res = new int[7]; // 用于存储合并结果
    std::map<int, int> res;
    while (p1 != NULL)
    {
        p2 = h2->next; // 每次从 h2 的开头开始
        while (p2 != NULL)
        {
            int coef = p1->coef * p2->coef; // 计算系数
            int exp = p1->exp + p2->exp;    // 计算指数
            res[exp] += coef;               // 根据指数累加系数
            p2 = p2->next;                  // 移动到 h2 的下一个节点
        }
        p1 = p1->next; // 移动到 h1 的下一个节点
    }

    // 创建一个临时链表存储结果
    NODE *rev = new NODE();
    rev->next = NULL;
    for (auto it : res)
    {
        if (it.second)
        {
            NODE *nxt = new NODE();
            nxt->coef = it.second;
            nxt->exp = it.first;
            nxt->next = rev->next;
            rev->next = nxt;
        }
    }

    NODE *prev = NULL;
    NODE *current = rev->next;
    while (current != NULL)
    {
        NODE *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    h3->next = prev;
    if (h3->next == NULL)
    {
        h3->next = new NODE();
        h3->next->coef = 0;
        h3->next->exp = 0;
        h3->next->next = NULL;
    }
}
