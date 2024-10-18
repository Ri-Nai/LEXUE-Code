struct Node * connect(struct Node *x, struct Node *y, struct Node *z)
{
    struct Node *t;

    if(y->score>x->score)
    {
        t=y;
        y=x;
        x=t;
    }
    if(z->score>x->score)
    {
        t=z;
        z=x;
        x=t;
    }
    if(z->score>y->score)
    {
        t=z;
        z=y;
        y=t;
    }
    x->next=y;
    y->next=z;
    z->next=NULL;
    return x;
}
