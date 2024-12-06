/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *h=malloc(sizeof(struct ListNode));
    h->next=head;h->val=0;
    struct ListNode *fast=head,*slow=h;
    while(n--)
    {
        fast=fast->next;
    }
    if(fast==NULL)
    {
        struct ListNode *next=head->next;
        free(head);
        head=next;
        return head;
    }
    while(fast)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return h->next;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fast=head,*slow=head;
    while(n--)
    {
        fast=fast->next;
    }
    if(fast==NULL)
    {
        struct ListNode *next=head->next;
        free(head);
        head=next;
        return head;
    }
    int sign=0;
    struct ListNode *pre=head;
    while(fast)
    {
        if(sign>0)
        {
            pre=pre->next;
        }
        slow=slow->next;
        fast=fast->next;
        sign+=1;
    }
    pre->next=pre->next->next;
    return head;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    struct ListNode *pre=head;
    while(n--)
    {
        fast=fast->next;
    }
    if(fast==NULL)
    {
        struct ListNode *next=head->next;
        free(head);
        head=next;
        return head;
    }
    while(fast)
    {
        pre=slow;
        fast=fast->next;
        slow=slow->next;
    }
    struct ListNode *curr=slow->next;
    free(slow);
    pre->next=curr;
    return head;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
       struct ListNode*slow,*fast,*prev;
       slow=fast=head;
       prev=NULL;
        while(n--){
            fast=fast->next;
        }
        while(fast){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==head){
            head=head->next;
            return head;
        }
        else{
            prev->next=slow->next;
            free(slow);
            slow=prev->next;
        }
      return head;
}
