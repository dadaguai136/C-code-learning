// ���ڴ洢Ԫ�صĽṹ��
typedef struct {
    int val;  // ��ֵ
    int row;  // �����ĸ��б�
    int idx;  // ���б��е�����
} Element;

// �ȽϺ�������������
int cmp(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

// ������
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    // ������Ԫ�ظ���
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += numsColSize[i];
    }
    
    // ����һ�������飬�洢����Ԫ�ؼ���λ����Ϣ
    Element* elements = (Element*)malloc(sizeof(Element) * total);
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            elements[index++] = (Element){nums[i][j], i, j};
        }
    }

    // ��Ԫ�ؽ�������
    qsort(elements, total, sizeof(Element), cmp);

    // ��������
    int* count = (int*)calloc(numsSize, sizeof(int)); // ��¼ÿ���б��ڴ����еĳ��ִ���
    int left = 0, right = 0, covered = 0; // covered��ʾ���ڸ����˶��ٸ���ͬ���б�
    int start = -1, end = -1, minRange = INT_MAX; // ��¼��С����

    // �ƶ���ָ��
    while (right < total) {
        // ����Ԫ�ص�����
        if (count[elements[right].row] == 0) {
            covered++;
        }
        count[elements[right].row]++;
        
        // ������ڰ������� k ���б��Ԫ��
        while (covered == numsSize) {
            // ������С����
            int range = elements[right].val - elements[left].val;
            if (range < minRange) {
                minRange = range;
                start = elements[left].val;
                end = elements[right].val;
            }

            // �Ƴ���ָ��Ԫ��
            count[elements[left].row]--;
            if (count[elements[left].row] == 0) {
                covered--;
            }
            left++;
        }
        right++;
    }

    // ������С����
    int* result = (int*)malloc(sizeof(int) * 2);
    result[0] = start;
    result[1] = end;
    *returnSize = 2;

    // �ͷ��ڴ�
    free(elements);
    free(count);

    return result;
}





typedef struct {
    int key;
    struct ListNode *val;
    UT_hash_handle hh;
} HashItem; 

struct ListNode *createListNode(int val) {
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = NULL;
    return p;
}

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    struct ListNode *p = createListNode(val);
    HashItem *pEntry = hashFindItem(obj, key);
    if (pEntry) {
        p->next = pEntry->val;
        pEntry->val = p;
        return true;
    }
    pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = p;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

struct ListNode* hashGetItem(HashItem **obj, int key) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return NULL;
    }
    return pEntry->val;
}

void freeList(struct ListNode *list) {
    while (list) {
        struct ListNode *p = list;
        list = list->next;
        free(p);
    }
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);  
        free(curr);
    }
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int n = numsSize;
    HashItem *indices = NULL;
    int xMin = INT_MAX, xMax = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < numsColSize[i]; j++) {
            int x = nums[i][j];
            hashAddItem(&indices, x, i);
            xMin = fmin(xMin, x);
            xMax = fmax(xMax, x);
        }
    }

    int freq[n];
    memset(freq, 0, sizeof(freq));
    int inside = 0;
    int left = xMin, right = xMin - 1;
    int bestLeft = xMin, bestRight = xMax;

    while (right < xMax) {
        ++right;
        if (hashFindItem(&indices, right)) {
            for (struct ListNode *p = hashGetItem(&indices, right); p; p = p->next) {
                int x = p->val;
                ++freq[x];
                if (freq[x] == 1) {
                    ++inside;
                }
            }
            while (inside == n) {
                if (right - left < bestRight - bestLeft) {
                    bestLeft = left;
                    bestRight = right;
                }
                if (hashFindItem(&indices, left)) {
                    for (struct ListNode *p = hashGetItem(&indices, left); p; p = p->next) {
                        int x = p->val;
                        --freq[x];
                        if (freq[x] == 0) {
                            --inside;
                        }
                    }
                }
                ++left;
            }
        }
    }
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = bestLeft;
    res[1] = bestRight;
    *returnSize = 2;
    hashFree(&indices);
    return res;
}
