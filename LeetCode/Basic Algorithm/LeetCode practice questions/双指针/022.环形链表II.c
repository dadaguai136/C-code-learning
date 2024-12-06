/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode h;
struct ListNode *detectCycle(struct ListNode *head) {
    h *fast=head;
    h *slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            while(1)
            {
                if(fast==head)
                {
                    return head;
                }
                head=head->next;
                fast=fast->next;
            }
        }
    }
    return NULL;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            struct ListNode *p=head;
            while(p!=slow)
            {
                p=p->next;
                slow=slow->next;
            }
            return p;
        }
    }
    return NULL;
}
