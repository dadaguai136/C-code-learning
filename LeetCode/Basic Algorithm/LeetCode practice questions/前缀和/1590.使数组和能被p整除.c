#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem; 

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);  
        free(curr);             
    }
}

int minSubarray(int* nums, int numsSize, int p) {
     int x = 0;
    for (int i = 0; i < numsSize; i++) {
        x = (x + nums[i]) % p;
    }
    if (x == 0) {
        return 0;
    }
    HashItem *index = NULL;
    int y = 0, res = numsSize;
    for (int i = 0; i < numsSize; i++) {
        hashSetItem(&index, y, i); // f[i] mod p = y，因此哈希表记录 y 对应的下标为 i
        y = (y + nums[i]) % p;
        if (hashFindItem(&index, (y - x + p) % p)) 
        {
            int val = hashGetItem(&index, (y - x + p) % p, 0);
            res = MIN(res, i - val + 1);
        }
    }
    hashFree(&index);
    return res == numsSize ? -1 : res;
}
