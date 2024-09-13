/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int listNodeSize(struct ListNode *head)
 {
    int size=0;
    while(head!=0)
    {
        size++;
        head=head->next;
    }
    return size;
 }
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int n=listNodeSize(head);
    int hash[n];
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]]++;
    }
    int ans=0;
    while(head!=NULL)
    {
        if(head!=NULL&&hash[head->val]==1)
        {
            ans++;
        }
        while(head!=NULL&&hash[head->val]==1)
        {
            head=head->next;
        }
        if(head!=NULL)
        {
            head=head->next;
        }
    }
    return ans;
}
