/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            struct ListNode *p=head;
            while(fast!=p)
            {
                fast=fast->next;
                p=p->next;
            }
            return p;
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
    struct ListNode *fast = head;
    struct ListNode *sow = head;
    int pos = -1;
    int i;
    for(;fast !=NULL;){
        if(fast->next == NULL || fast->next->next == NULL){
            return NULL;
        }
        fast = fast->next->next;
        sow = sow->next;
        if( fast == sow){
            break;
        }
    }
    fast = head;
    for(;fast!= sow;){
        fast=fast->next;
        sow =sow->next;
    }
    return fast;
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

struct ListNode* detectCycle(struct ListNode* head) {
    hashtable = NULL;
    while (head != NULL) {
        if (find(head) != NULL) {
            return head;
        }
        insert(head);
        head = head->next;
    }
    return false;
}
