/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ans=(int *)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    for(int i=0,j=numsSize-1,pos=numsSize-1;i<=j;)
    {
        if(nums[i]*nums[i]>nums[j]*nums[j])
        {
            ans[pos]=nums[i]*nums[i];
            i++;
        }
        else
        {
            ans[pos]=nums[j]*nums[j];
            j--;
        }
        --pos;
    }
    return ans;
}





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int start=-1;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<0)
        {
            start=i;
        }
        else
        {
            break;
        }
    }
    int i=start,j=start+1;
    int *ret=(int *)malloc(sizeof(int)*numsSize);
    *returnSize=0;
    while(i>=0||j<numsSize)
    {
        if(i<0)
        {
            ret[(*returnSize)++]=nums[j]*nums[j];
            j++;
        }
        else if(j==numsSize)
        {
            ret[(*returnSize)++]=nums[i]*nums[i];
            i--;
        }
        else if(nums[i]*nums[i]<nums[j]*nums[j])
        {
            ret[(*returnSize)++]=nums[i]*nums[i];
            i--;
        }
        else
        {
            ret[(*returnSize)++]=nums[j]*nums[j];
            j++;
        }
    }
    return ret;
}
