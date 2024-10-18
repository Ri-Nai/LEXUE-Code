void Delete(void)
{
    NODE *p=phead,*q=phead->link;
    int mp[256]={};
    mp['a']=mp['e']=mp['i']=mp['o']=mp['u']=1;
    while(q!=NULL)
    {
        if(q->value%2 || mp[q->ch])
            p->link=q->link;
        else p=p->link;
        q=q->link;
    }
}
