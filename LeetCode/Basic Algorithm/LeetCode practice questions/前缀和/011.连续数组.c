#define MAX(a, b) ((a) > (b) ? (a) : (b))
int findMaxLength(int* nums, int numsSize){
    int prefixSum[numsSize];
    int hashmap[2 * numsSize];
    memset(prefixSum, 0, numsSize * sizeof(int));
    memset(hashmap, -1, 2 * numsSize * sizeof(int));
    
    // 前缀和
    prefixSum[0] = ((nums[0] == 0) ? (-1) : (1));
    for (int i = 1; i < numsSize; i++) {
        prefixSum[i] = prefixSum[i - 1] + ((nums[i] == 0) ? (-1) : (1));
    }
    // 哈希表记录，O（1）的时间复杂度
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        if (prefixSum[i] < 0) {
            if (hashmap[prefixSum[i] + numsSize] == -1) {
                hashmap[prefixSum[i] + numsSize] = i;
            } else { // 冲突，更新长度
                res = MAX(res, i - hashmap[prefixSum[i] + numsSize]);
            }
            
        } else if (prefixSum[i] > 0){
            if (hashmap[prefixSum[i]] == -1) {
                hashmap[prefixSum[i]] = i;
            } else {
                res = MAX(res, i - hashmap[prefixSum[i]]);
            }
        } else {
            res = i + 1;
        }
    }
    return res;
}




struct HashTable {
    int key, val;
    UT_hash_handle hh;
};

int findMaxLength(int* nums, int numsSize) {
    int maxLength = 0;
    struct HashTable* hashTable = NULL;
    struct HashTable* tmp = malloc(sizeof(struct HashTable));
    tmp->key = 0, tmp->val = -1;
    HASH_ADD_INT(hashTable, key, tmp);
    int counter = 0;
    int n = numsSize;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (num == 1) {
            counter++;
        } else {
            counter--;
        }
        HASH_FIND_INT(hashTable, &counter, tmp);
        if (tmp != NULL) {
            int prevIndex = tmp->val;
            maxLength = fmax(maxLength, i - prevIndex);
        } else {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = counter, tmp->val = i;
            HASH_ADD_INT(hashTable, key, tmp);
        }
    }
    return maxLength;
}




#define maxn 100001
int sum[maxn];

int findMaxLength(int* nums, int numsSize){
    sum[0]=nums[0]==0?-1:1;
    for(int i=1;i<numsSize;i++)
    {
        sum[i]=sum[i-1]+(nums[i]==0?-1:1);
    }
    int hash[maxn*2];
    memset(hash,-1,sizeof(hash));
    int ret=0;
    for(int j=0;j<numsSize;j++)
    {
        if(sum[j]<0)
        {
            if(hash[sum[j]+numsSize]==-1)
            {
                hash[sum[j]+numsSize]=j;
            }
            else
            {
                ret=fmax(ret,j-hash[sum[j]+numsSize]);
            }
        }
        else if(sum[j]>0)
        {
            if(hash[sum[j]]==-1)
            {
                hash[sum[j]]=j;
            }
            else
            {
                ret=fmax(ret,j-hash[sum[j]]);
            }
        }
        else
        {
            ret=j+1;
        }
    }
    return ret;
}




