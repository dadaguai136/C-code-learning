typedef struct hashNode{
    int prefixSum;
    int cnt;
    UT_hash_handle hh;
}hashNode;

int subarraySum(int* nums,int numsSize,int k){
    if(nums==NULL){
        return 0;
    }
    int retCnt=0;
    hashNode* hashSet=NULL;
    int prefixSum=0;
    hashNode* tmpNode=(hashNode*)malloc(sizeof(hashNode));
    tmpNode->prefixSum=prefixSum;
    tmpNode->cnt=1;
    HASH_ADD_INT(hashSet,prefixSum,tmpNode);
    for(int i=0;i<numsSize;i++){
        prefixSum+=nums[i];
        int value=prefixSum-k;
        HASH_FIND_INT(hashSet,&value,tmpNode);
        if(tmpNode!=NULL){
            retCnt+=tmpNode->cnt;
        }
        HASH_FIND_INT(hashSet,&prefixSum,tmpNode);
        if(tmpNode!=NULL){
            tmpNode->cnt++;
        }else{
            tmpNode=(hashNode*)malloc(sizeof(hashNode));
            tmpNode->prefixSum=prefixSum;
            tmpNode->cnt=1;
            HASH_ADD_INT(hashSet,prefixSum,tmpNode);
        }
    }
    return retCnt;
}




typedef struct Node{
    int key;
    int value;
    struct Node * next;
} HashNode;

int hash(int key, int numsSize)
{
    return key & (numsSize - 1); 
}

bool containKey(HashNode * hashtable, int key, int numsSize)
{
    HashNode * head = &hashtable[hash(key, numsSize)];
    HashNode * tail = head->next; 
    while(tail){
        if(tail->key == key) return true;
        tail = tail->next;
    }
    return false;
}

int getKey(HashNode * hashtable, int key, int numsSize)
{
    HashNode * head = &hashtable[hash(key, numsSize)];
    HashNode * tail = head->next;
    while(tail){
        if(tail->key == key) return tail->value;
        tail = tail->next;
    }
    return -1; 
}

void push(HashNode * hashtable, int key, int numsSize)
{
    HashNode * head = &hashtable[hash(key, numsSize)];
    HashNode * tail = head->next;
    while(tail){
        if(tail->key == key){
            tail->value++;
            return;
        }
        tail = tail->next;
    }
    // 头插建表
    HashNode * q = malloc(sizeof(HashNode));
    q->key = key;
    q->value = 1;
    q->next = head->next;
    head->next = q;
}

int subarraySum(int* nums, int numsSize, int k){
    HashNode * hashtable = malloc(sizeof(HashNode) * numsSize);
    memset(hashtable, 0, sizeof(HashNode) * numsSize);
    push(hashtable, 0, numsSize);
    int pre = 0, cnt = 0;
    for(int i = 0; i < numsSize; i++){
        pre += nums[i];
        if(containKey(hashtable, pre - k, numsSize))
            cnt += getKey(hashtable, pre - k, numsSize);
        push(hashtable, pre, numsSize);
    }
    return cnt;
}




#define MAX_NODE_LEN 20000
#define HASH_TBL_LEN (MAX_NODE_LEN * 2) + 1
#define INVALID_VALUE INT_MIN

typedef struct {
    int key;
    int value;
} HashNode;

HashNode g_hashTbl[HASH_TBL_LEN];

void InitHashTbl()
{
    for (int i = 0; i < HASH_TBL_LEN; i++) {
        g_hashTbl[i].key = INVALID_VALUE;
        g_hashTbl[i].value = INVALID_VALUE;
    }
}

int GetHashIndex(int key)
{
    return (abs(key) * 131) % MAX_NODE_LEN;
}

void AddNode(int key, int value)
{
    int hashIndex = GetHashIndex(key);
    for (int i = hashIndex; i < HASH_TBL_LEN; i++) {
        if (g_hashTbl[i].key == INVALID_VALUE) {
            g_hashTbl[i].key = key;
            g_hashTbl[i].value = value;
            break;
        }
        continue;
    }
}

HashNode *FindNode(int key)
{
    int hashIndex = GetHashIndex(key);
    for (int i = hashIndex; i < HASH_TBL_LEN; i++) {
        if (g_hashTbl[i].key == INVALID_VALUE) {
            return NULL;
        }
        if (g_hashTbl[i].key == key) {
            return &(g_hashTbl[i]);
        }
    }
    return NULL;
}

int subarraySum(int *nums, int numsSize, int k)
{
    HashNode *node = NULL;
    InitHashTbl();
    AddNode(0, 1);
    int pre = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        pre += nums[i];
        node = FindNode(pre - k);
        if (node != NULL) {
            count += node->value;
        }
        node = FindNode(pre);
        if (node != NULL) {
            node->value++;
        } else {
            AddNode(pre, 1);
        }
    }
    return count;
}




// 暴力美学：20行C代码
int subarraySum(int *nums, int numsSize, int k) {
    int count = 0;
    // 弄个大数组做个暴力的Hash表，大概4*20M*2=160M。用calloc初始化为全零。
    int *maps = (int *)calloc(1001 * 20001 * 2, sizeof(int));
    // 前缀和可能是负数，把指针放到中间位置
    int *map = maps + 1001 * 20001 * 1;
    // 补一个最前面的前缀和，用了下标0
    int sum = 0;
    map[sum]++;
    // 下标从1开始，注意=
    for (int i = 1; i <= numsSize; i++) {
        // 注意-1
        sum += nums[i - 1];
        if (map[sum - k] > 0) {
            count += map[sum - k];
        }
        map[sum]++;
    }
    free(maps);
    return count;
}
