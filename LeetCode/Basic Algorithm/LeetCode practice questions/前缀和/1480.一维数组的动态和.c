/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int *ret=(int *)malloc(sizeof(int)*numsSize);
    ret[0]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        ret[i]=ret[i-1]+nums[i];
    }
    return ret;
}






/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int *ret=(int *)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    for(int i=0;i<numsSize;i++)
    {
        if(i==0)
        {
            ret[0]=nums[0];
        }
        else
        {
            ret[i]=nums[i]+ret[i-1];
        }
    }
    return ret;
}
