/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *pre=NULL;
    struct ListNode *curr=head;
    while(curr)
    {
        while(pre&&pre->val==curr->val)
        {
            pre->next=curr->next;
            curr=pre->next;
            if(!curr)
            {
                break;
            }
        }
        if(!curr)
        {
            break;
        }
        pre=curr;
        curr=curr->next;
    }
    return head;
}
