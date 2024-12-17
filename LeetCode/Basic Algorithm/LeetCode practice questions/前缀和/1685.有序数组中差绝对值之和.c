/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int * result = (int *) malloc(numsSize * 4);
    int * pre = (int *) malloc(numsSize * 4);
    int * aft = (int *) malloc(numsSize * 4);
    memset(result,0,numsSize * 4);
    memset(pre,0,numsSize * 4);
    memset(aft,0,numsSize * 4);
    for(int i = 1;i<numsSize;i++)
    {
        pre[i] = pre[i-1] + nums[i-1];
        aft[numsSize-i-1] = aft[numsSize-i] + nums[numsSize-i];
    }
    for(int i = 0;i<numsSize;i++)
    {
        result[i] = (nums[i] * i - pre[i]) + (aft[i] - nums[i] * (numsSize -i -1));
    }
    return result;
}





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getSumAbsoluteDifferences(int *nums, int numsSize, int *returnSize)
{
    int *result = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        result[i] = 0;
        result[0] += nums[i];
    }
    result[0]=result[0]- numsSize * nums[0];
    for (int j = 1; j < numsSize; j++)
        result[j] = (2 * j - numsSize) * (nums[j] - nums[j - 1]) + result[j - 1];
    return result;
}
