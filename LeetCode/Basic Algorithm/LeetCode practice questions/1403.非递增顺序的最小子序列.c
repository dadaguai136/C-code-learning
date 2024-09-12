/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(const void *pa,const void *pb)
 {
    return *(int *)pa-*(int *)pb;
 }
int* minSubsequence(int* nums, int numsSize, int* returnSize) {
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    int *ret=malloc(sizeof(int)*numsSize);
    int curr=0;
    int size=0;
    for(int i=numsSize-1;i>=0;i--)
    {
        curr+=nums[i];
        ret[size++]=nums[i];
        if(sum-curr<curr)
        {
            break;
        }
    }
    *returnSize=size;
    return ret;
}
