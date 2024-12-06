/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    struct ListNode *fast=head->next;
    struct ListNode *slow=head;
    while(fast!=slow)
    {
        if(fast==NULL||fast->next==NULL)
        {
            return false;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)
    {
        return false;
    }
    struct ListNode *arr[10001]={};
    arr[0]=head;
    int size=0;
    struct ListNode *p=head;
    while(head->next)
    {
        head=head->next;
        arr[++size]=head;
        p->next=NULL;
        p=head;
    }
    for(int i=0;i<size;i++)
    {
        if(arr[i]==p)
        {
            return true;
        }
    }
    return false;
}




struct hashTable {
    struct ListNode* key;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(struct ListNode* ikey) {
    struct hashTable* tmp;
    HASH_FIND_PTR(hashtable, &ikey, tmp);
    return tmp;
}

void insert(struct ListNode* ikey) {
    struct hashTable* tmp = malloc(sizeof(struct hashTable));
    tmp->key = ikey;
    HASH_ADD_PTR(hashtable, key, tmp);
}

bool hasCycle(struct ListNode* head) {
    hashtable = NULL;
    while (head != NULL) {
        if (find(head) != NULL) {
            return true;
        }
        insert(head);
        head = head->next;
    }
    return false;
}
