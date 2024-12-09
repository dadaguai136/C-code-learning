// 用于存储元素的结构体
typedef struct {
    int val;  // 数值
    int row;  // 来自哪个列表
    int idx;  // 在列表中的索引
} Element;

// 比较函数，用于排序
int cmp(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

// 主函数
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    // 计算总元素个数
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += numsColSize[i];
    }
    
    // 创建一个大数组，存储所有元素及其位置信息
    Element* elements = (Element*)malloc(sizeof(Element) * total);
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            elements[index++] = (Element){nums[i][j], i, j};
        }
    }

    // 对元素进行排序
    qsort(elements, total, sizeof(Element), cmp);

    // 滑动窗口
    int* count = (int*)calloc(numsSize, sizeof(int)); // 记录每个列表在窗口中的出现次数
    int left = 0, right = 0, covered = 0; // covered表示窗口覆盖了多少个不同的列表
    int start = -1, end = -1, minRange = INT_MAX; // 记录最小区间

    // 移动右指针
    while (right < total) {
        // 加入元素到窗口
        if (count[elements[right].row] == 0) {
            covered++;
        }
        count[elements[right].row]++;
        
        // 如果窗口包含所有 k 个列表的元素
        while (covered == numsSize) {
            // 更新最小区间
            int range = elements[right].val - elements[left].val;
            if (range < minRange) {
                minRange = range;
                start = elements[left].val;
                end = elements[right].val;
            }

            // 移出左指针元素
            count[elements[left].row]--;
            if (count[elements[left].row] == 0) {
                covered--;
            }
            left++;
        }
        right++;
    }

    // 返回最小区间
    int* result = (int*)malloc(sizeof(int) * 2);
    result[0] = start;
    result[1] = end;
    *returnSize = 2;

    // 释放内存
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
