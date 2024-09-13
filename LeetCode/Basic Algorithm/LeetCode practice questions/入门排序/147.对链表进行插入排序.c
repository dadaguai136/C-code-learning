struct ListNode* insertionSortList(struct ListNode* head) {
    if(head==NULL)
    {
        return NULL;
    }
    struct ListNode *h=(struct ListNode *)malloc(sizeof(struct ListNode));
    h->next=head;
    struct ListNode *pre=head,*cur=head->next;
    struct ListNode *temp;
    while(cur!=NULL)
    {
        if(cur->val>=pre->val)
        {
            cur=cur->next;
            pre=pre->next;
        }
        else
        {
            temp=h;
            while(temp->next->val<cur->val)
            {
                temp=temp->next;
            }
            pre->next=cur->next;
            cur->next=temp->next;
            temp->next=cur;
            cur=pre->next;
        }
    }
    return h->next;
}
