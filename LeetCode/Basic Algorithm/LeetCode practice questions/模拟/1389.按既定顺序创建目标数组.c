/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    *returnSize=indexSize;
    int *ret=malloc(sizeof(int)*indexSize);
    int tail=-1;
    for(int i=0;i<indexSize;i++)
    {
        tail++;
        for(int j=tail;j>index[i];j--)
        {
            ret[j]=ret[j-1];
        }
        ret[index[i]]=nums[i];
    }
    return ret;
}
