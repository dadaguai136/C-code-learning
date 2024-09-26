int findTheWinner(int n, int k){
    struct ListNode * head = NULL;
    struct ListNode * tail = NULL;
    for (int i = 1; i <= n; i++) {
        struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = i;
        node->next = NULL;
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
    while (head != tail) {
        for (int i = 1; i < k; i++) {
            struct ListNode * node = head;
            head = head->next;
            tail->next = node;
            tail = tail->next;
            tail->next = NULL;
        }
        struct ListNode * node = head;
        head = head->next;
        free(node);
    }
    int res = head->val;
    free(head);
    return res;
}
