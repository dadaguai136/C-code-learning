/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxScoreIndices(int* nums, int numsSize, int* returnSize) {
    int *a=(int*)malloc(sizeof(int)*numsSize);
    int top=-1,num0=0,num1=0,max=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
            num1++;
    }
    for(int i=0;i<=numsSize;i++)
    {
        if(num0+num1>max)
        {
            max=num0+num1;
            top=-1;
            a[++top]=i;
        }
        else if(num0+num1==max)
        {
            a[++top]=i;
        }
        if(i<numsSize)
        {
            if(nums[i]==0)
                num0++;
            else
                num1--;
        }
    }
    *returnSize=top+1;
    return a;
}




int* maxScoreIndices(int* nums, int numsSize, int* returnSize)
{
    int resSize = 0;
    int* res = (int*)malloc(sizeof(int) * numsSize);
    memset(res, 0, sizeof(int) * numsSize);
    int allSum = 0;
    for (int i = 1; i < numsSize;i++) {
        allSum += nums[i];
    }
    int max = -1;
    int preSum = 0;
    for (int i = 0; i <= numsSize; i++) {
        preSum += i > 0 ? nums[i - 1] : 0;
        int val = allSum - preSum + i - preSum;
        if (val > max) {
            resSize = 0;
            res[resSize++] = i;
            max = val;
        } else if (val == max) {
            res[resSize++] = i;
        }
    }
    *returnSize = resSize;
    return res;
}
