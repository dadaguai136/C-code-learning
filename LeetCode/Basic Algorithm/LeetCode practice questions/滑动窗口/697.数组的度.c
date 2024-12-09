struct HashTable {
    int key;
    int num, add1, add2;
    UT_hash_handle hh;
};

int findShortestSubArray(int* nums, int numsSize) {
    struct HashTable* hashTable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct HashTable* tmp;
        HASH_FIND_INT(hashTable, &nums[i], tmp);
        if (tmp != NULL) {
            tmp->num++;
            tmp->add2 = i;
        } else {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = nums[i];
            tmp->num = 1;
            tmp->add1 = i;
            tmp->add2 = i;
            HASH_ADD_INT(hashTable, key, tmp);
        }
    }
    int maxNum = 0, minLen = 0;
    struct HashTable *s, *tmp;
    HASH_ITER(hh, hashTable, s, tmp) {
        if (maxNum < s->num) {
            maxNum = s->num;
            minLen = s->add2 - s->add1 + 1;
        } else if (maxNum == s->num) {
            if (minLen > s->add2 - s->add1 + 1) {
                minLen = s->add2 - s->add1 + 1;
            }
        }
    }
    return minLen;
}




int cnt[50000];
int findShortestSubArray(int* nums, int numsSize){
    int i;
    int left= 0;
    int right= 0;
    int maxCnt = 0;
    int res    = numsSize;
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < numsSize; i++) {
        int temp = ++cnt[nums[i]];
        if (temp > maxCnt) {
            maxCnt = temp;
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (right = 0; right < numsSize; right++) {
        cnt[nums[right]]++;
        while (cnt[nums[right]] == maxCnt) {
            int temp = right - left + 1;
            if (temp < res) {
                res = temp;
            }
            cnt[nums[left++]]--;
        }
    }
    return res;
}
