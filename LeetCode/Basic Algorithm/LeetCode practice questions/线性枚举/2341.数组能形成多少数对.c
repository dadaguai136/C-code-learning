/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(const void *pa,const void *pb)
 {
    return *(int *)pa-*(int *)pb;
 }
int* numberOfPairs(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    *returnSize=2;
    int *ans=malloc(sizeof(int)*2);
    ans[0]=0;
    ans[1]=numsSize;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]==nums[i-1])
        {
            ans[0]++;
            ans[1]-=2;
            i++;
        }
    }
    return ans;
}
