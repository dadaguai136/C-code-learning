/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *suf=(int *)malloc(sizeof(int)*numsSize);
    suf[numsSize-1]=1;
    for(int i=numsSize-2;i>=0;i--)
    {
        suf[i]=suf[i+1]*nums[i+1];
    }
    int pre=1;
    for(int i=0;i<numsSize;i++)
    {
        suf[i]*=pre;
        pre*=nums[i];
    }
    *returnSize=numsSize;
    return suf;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *pre=(int *)malloc(sizeof(int)*numsSize);
    pre[0]=1;
    for(int i=1;i<numsSize;i++)
    {
        pre[i]=pre[i-1]*nums[i-1];
    }
    int *suf=(int *)malloc(sizeof(int)*numsSize);
    suf[numsSize-1]=1;
    for(int i=numsSize-2;i>=0;i--)
    {
        suf[i]=suf[i+1]*nums[i+1];
    }
    int *ans=(int *)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    for(int i=0;i<numsSize;i++)
    {
        ans[i]=pre[i]*suf[i];
    }
    free(pre);
    free(suf);
    return ans;
}
