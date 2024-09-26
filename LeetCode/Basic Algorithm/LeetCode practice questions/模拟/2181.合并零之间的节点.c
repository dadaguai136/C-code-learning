/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode *cur=head->next;
    struct ListNode *slow=head->next;
    int sum=0;
    while(cur)
    {
        if(cur->val==0)
        {
            slow->val=sum;
            sum=0;
            if(cur->next==NULL)
            {
                slow->next=NULL;
            }
            else
            {
                slow=slow->next;
            }
        }
        else
        {
            sum+=cur->val;
        }
        cur=cur->next;
    }
    return head->next;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *creatListNode(int val)
{
    struct ListNode *obj=(struct ListNode *)malloc(sizeof(struct ListNode));
    obj->val=val;
    obj->next=NULL;
    return obj;
}
struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode *dummy=creatListNode(0);
    struct ListNode *tail=dummy;
    int total=0;
    for(struct ListNode *cur=head->next;cur;cur=cur->next)
    {
        if(cur->val==0)
        {
            struct LsitNode *node=creatListNode(total);
            tail->next=node;
            tail=tail->next;
            total=0;
        }
        else
        {
            total+=cur->val;
        }
    }
    return dummy->next;
}
